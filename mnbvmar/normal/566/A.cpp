#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int MaxN = 100005;
const int SumAll = 800005;

int N;
string s1[MaxN], s2[MaxN];
bool avail1[MaxN], avail2[MaxN];

void input(){
    ios_base::sync_with_stdio(false);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> s1[i];
    }
    for(int i = 0; i < N; i++){
        cin >> s2[i];
    }
}

const int NumChars = 26;

struct TrieNode {
    vector<int> first, second;
    int children[NumChars];
};

TrieNode trie[SumAll];
int trieSize;
int maxDepth;
vector<int> nodeDepths[SumAll];

void add_word(string word, int id, bool isFirst){
    int ptr = 0;
    if(isFirst) trie[ptr].first.push_back(id); else trie[ptr].second.push_back(id);

    int depth = 0;
    for(char ch : word){
        int pos = (ch-'a');
        depth++;
        if(trie[ptr].children[pos] == 0){
            trie[ptr].children[pos] = trieSize;
            nodeDepths[depth].push_back(trieSize);
            maxDepth = max(maxDepth, depth);
            trieSize++;
        }
        ptr = trie[ptr].children[pos];
        if(isFirst) trie[ptr].first.push_back(id); else trie[ptr].second.push_back(id);
    }
}



int main(){
    input();
    trieSize = 1;
    maxDepth = 0;
    nodeDepths[0].push_back(0);

    for(int i = 0; i < N; i++){
        add_word(s1[i], i+1, true);
        add_word(s2[i], i+1, false);
    }
    fill(avail1, avail1+N+1, true);
    fill(avail2, avail2+N+1, true);

    vector<int> matching(N+1);
    int result = 0;
    for(int depth = maxDepth; depth >= 0; depth--){
        for(int v : nodeDepths[depth]){
            auto& fst = trie[v].first,
                & snd = trie[v].second;
            int fptr = 0, sptr = 0;
            int fsiz = trie[v].first.size(), ssiz = trie[v].second.size();

            while(true){
                int ss1 = -1, ss2 = -1;
                while(fptr < fsiz){
                    if(avail1[fst[fptr]]){
                        ss1 = fst[fptr]; break;
                    }
                    fptr++;
                }
                while(sptr < ssiz){
                    if(avail2[snd[sptr]]){
                        ss2 = snd[sptr]; break;
                    }
                    sptr++;
                }
                if(ss1 == -1 || ss2 == -1) break;

//                printf("%d with %d\n", ss1, ss2);
                matching[ss1] = ss2;
                avail1[ss1] = false;
                avail2[ss2] = false;
                result += depth;
            }
        }
    }

    printf("%d\n", result);
    for(int i = 1; i <= N; i++){
        printf("%d %d\n", i, matching[i]);
    }
}