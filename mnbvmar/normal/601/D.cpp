#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

template<typename TH>
void debug_vars(const char* data, TH head){
    cerr << data << "=" << head << "\n";
}

template<typename TH, typename... TA>
void debug_vars(const char* data, TH head, TA... tail){
    while(*data != ',') cerr << *data++;
    cerr << "=" << head << ",";
    debug_vars(data+1, tail...);
}

#ifdef LOCAL
#define debug(...) debug_vars(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#endif

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).begin())

/////////////////////////////////////////////////////////


const int MaxN = 300005;
const int MaxChars = 26;

struct TrieNode {
  int trieSize;
  int nextNode[MaxChars];
};

TrieNode trie[MaxN*3];



int N;
int weights[MaxN];
string word;

vector<int> adj[MaxN];
int numDiff[MaxN];


void join_trie(int from, int to){
  for(int i = 0; i < MaxChars; i++){
    int &nf = trie[from].nextNode[i],
        &nt = trie[to].nextNode[i];

    if(nf){
      if(!nt){
        nt = nf;
        trie[to].trieSize += trie[nf].trieSize;
      } else {
        trie[to].trieSize -= trie[nt].trieSize;
        join_trie(nf, nt);
        trie[to].trieSize += trie[nt].trieSize;
      }
    }
  }
}


void dfs(int v, int par){
  vector<int> children;
  int largest = -1;

  for(int s : adj[v]){
    if(s == par) continue;

    dfs(s, v);
    children.push_back(s);
    if(largest == -1 || trie[largest].trieSize < trie[s].trieSize){
      largest = s;
    }
  }

  if(largest != -1){
    for(int ch : children){
      if(ch != largest){
        join_trie(ch, largest);
      }
    }
    
    trie[v].nextNode[word[v]-'a'] = largest;
    trie[v].trieSize = trie[largest].trieSize + 1;
  }

  numDiff[v] = trie[v].trieSize - 1;

}


void input(){
  ios_base::sync_with_stdio(0);
  cin >> N;
  for(int i = 0; i < N; i++){
    cin >> weights[i];
  }
  cin >> word;
  
  for(int i = 0; i < N-1; i++){
    int u, v;
    cin >> u >> v;
    u--; v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
}

int main(){
  input();

  for(int i = 0; i < N; i++){
    trie[i].trieSize = 2;
    trie[i].nextNode[word[i]-'a'] = N+i;
    trie[N+i].trieSize = 1;
  }

  dfs(0, 0);
  for(int i = 0; i < N; i++){
    debug(i, numDiff[i]);
  }

  int best = -1, numBest = 0;
  for(int i = 0; i < N; i++){
    int value = numDiff[i] + weights[i];
    if(value > best){
      best = value; numBest = 0;
    }

    if(value == best) numBest++;
  }

  cout << best << endl << numBest << endl;
}