#define NDEBUG
#include <cassert>
#include <cctype>
#include <cstdio>
#include <unistd.h>
#include <unordered_set>
using namespace std;

#define repeat(n) for (int repc = (n); repc > 0; --repc)

const int MAXN = 50005;

int ASHTON_THRESHOLD;

struct State {
  bool online;
  unordered_set<int> friends, subs;
  bool ashton;
  int online_friends_cached;
} states[MAXN];

void go_online(int id) {
  assert(!states[id].online);
  states[id].online = true;
  for (int x : states[id].subs) {
    ++states[x].online_friends_cached;
  }
}

void go_offline(int id) {
  assert(states[id].online);
  states[id].online = false;
  for (int x : states[id].subs) {
    --states[x].online_friends_cached;
  }
}

void check_ashton(int id) {
  State &state = states[id];
  if (!state.ashton && (int)state.friends.size() > ASHTON_THRESHOLD) {
    state.ashton = true;
    state.online_friends_cached = 0;
    for (int x : state.friends) {
      state.online_friends_cached += states[x].online;
      states[x].subs.insert(id);
    }
  }
}

void make_friends(int a, int b) {
  check_ashton(a);
  states[a].friends.insert(b);
  if (states[a].ashton) {
    states[a].online_friends_cached += states[b].online;
    states[b].subs.insert(a);
  }
}

void unfriend(int a, int b) {
  states[a].friends.erase(b);
  if (states[a].ashton) {
    states[a].online_friends_cached -= states[b].online;
    states[b].subs.erase(a);
  }
}

class FastInput {
public:
  FastInput() : ptr_(buf_), end_(buf_) { }

  unsigned char readchar() {
    if (ptr_ == end_) {
      ptr_ = buf_;
      end_ = buf_ + read(0, buf_, MAXBUF);
    }
    return *ptr_++;
  }

  int readint() {
    unsigned char ch;
    while (isspace(ch = readchar())) ;
    if (ch == '-') {
      return -int(readuint());
    } else {
      --ptr_;
      return readuint();
    }
  }

  unsigned readuint() {
    unsigned char ch;
    while (isspace(ch = readchar())) ;

    unsigned result = ch - '0';
    while (isdigit(ch = readchar())) {
      result = 10 * result + ch - '0';
    }
    return result;
  }

private:
  static const int MAXBUF = 8192;
  char buf_[MAXBUF];
  char *ptr_, *end_;
};

class FastOutput {
public:
  FastOutput() : ptr_(buf_), end_(buf_ + BUFSIZE) { }

  ~FastOutput() {
    flush();
  }

  void flush() {
    int rv = write(1, buf_, ptr_ - buf_);
    (void)rv;
    ptr_ = buf_;
  }

  void putchar(unsigned char ch) {
    if (ptr_ == end_) {
      flush();
    }
    *ptr_++ = ch;
  }

  void writeuint(unsigned x) {
    char buf[50], *p = buf;
    do { *p++ = '0'+x%10; x/=10; } while (x > 0) ;
    do putchar(*--p); while (p != buf);
  }

private:
  static const int BUFSIZE = 8192;
  char buf_[BUFSIZE];
  char *ptr_, *end_;
};

int main() {
  FastInput fin;
  FastOutput fout;
  int n = fin.readuint(), m = fin.readuint(), q = fin.readuint();

  // ASHTON_THRESHOLD = sqrt(m+q);
  ASHTON_THRESHOLD = 100;

  int o = fin.readuint();
  repeat (o) {
    int id = fin.readuint();
    go_online(id);
  }

  repeat (m) {
    int a = fin.readuint(), b = fin.readuint();
    make_friends(a, b);
    make_friends(b, a);
  }

  repeat (q) {
    char op;
    do {
      op = fin.readchar();
    } while (isspace(op));
    if (op == 'O') {
      int id = fin.readuint();
      go_online(id);
    } else if (op == 'F') {
      int id = fin.readuint();
      go_offline(id);
    } else if (op == 'A') {
      int a = fin.readuint(), b = fin.readuint();
      make_friends(a, b);
      make_friends(b, a);
    } else if (op == 'D') {
      int a = fin.readuint(), b = fin.readuint();
      unfriend(a, b);
      unfriend(b, a);
    } else if (op == 'C') {
      int id = fin.readuint();
      State &state = states[id];
      if (state.ashton) {
        // fprintf(stderr, "here1\n");
        fout.writeuint(state.online_friends_cached);
        fout.putchar('\n');
      } else {
        // fprintf(stderr, "here2\n");
        int ans = 0;
        for (int x : state.friends) {
          ans += states[x].online;
        }
        fout.writeuint(ans);
        fout.putchar('\n');
      }
    } else {
      assert(false);
    }
  }

  return 0;
}