#include <iostream>
#include <vector>

using namespace std;

#define INFN 54

const string F0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
const string P1 = "What are you doing while sending \"";
const string P2 = "\"? Are you busy? Will you send \"";
const string P3 = "\"?";

long long fsz[INFN];

long long get_size(int n) {
  return fsz[min(INFN - 1, n)];
}

char findc(int n, long long o) {
  if (n == 0) return F0[o];

  if (o < P1.size()) return P1[o];
  o -= P1.size();

  if (o < get_size(n - 1)) return findc(n - 1, o);
  o -= get_size(n - 1);

  if (o < P2.size()) return P2[o];
  o -= P2.size();

  if (o < get_size(n - 1)) return findc(n - 1, o);
  o -= get_size(n - 1);

  return P3[o];
}

int main() {
  fsz[0] = F0.size();
  for (int i = 1; i < INFN; i++) {
    fsz[i] = fsz[i - 1] * 2 + P1.size() + P2.size() + P3.size();
  }

  int Q; cin >> Q;
  for (int q = 1; q <= Q; q++) {
    long long N, K;
    cin >> N >> K;

    if (K > get_size(N)) {
      cout << '.';
    } else {
      cout << findc(N, K - 1);
    }
  }
  cout << '\n';

  return 0;
}