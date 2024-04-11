#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int N,M;
char S[200005],T[200005];
long long pw[2][200005],ha[2][26],me[2][26],cut[26],mul[2]={97,107}; int see = 0;
map<long long, int> chk[2];

int main()
{
    scanf ("%d %d",&N,&M);
    scanf ("%s %s",S,T);

    for (int a=0;a<2;a++){
        pw[a][0] = 1;
        for (int i=1;i<=M;i++) pw[a][i] = pw[a][i-1] * mul[a];
        for (int j=0;j<M;j++){
            me[a][T[j]-'a'] += pw[a][M-j-1];
        }
        see = 0;
        for (int j=0;j<26;j++) if (me[a][j] != 0) chk[a][me[a][j]] = j, see++;
        sort(me[a],me[a]+26);
    }

    vector<int> ans;
    for (int i=0;i<N;i++){
        bool good = 1;
        for (int a=0;a<2;a++){
            for (int j=0;j<26;j++) ha[a][j] *= mul[a];
            ha[a][S[i]-'a']++;
            if (i >= M) ha[a][S[i-M]-'a'] -= pw[a][M];
            map<int, int> col; int s = 0;
            for (int j=0;j<26;j++) if (ha[a][j] != 0){
                if (!chk[a].count(ha[a][j])){
                    good = 0;
                }
                else{
                    s++;
                    int u = chk[a][ha[a][j]];
                    if (col.count(u) && col[u] != j) good = 0;
                    col[u] = j;
                    if (col.count(j) && col[j] != u) good = 0;
                    col[j] = u;
                }
            }
            if (s != see) good = 0;
        }
        if (good) ans.push_back(i-M+2);
    }

    printf ("%u\n",ans.size());
    for (int x : ans) printf ("%d ",x);
    puts("");

    return 0;
}