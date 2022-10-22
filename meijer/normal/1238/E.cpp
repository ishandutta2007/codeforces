#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back

const int MX=2e5, N=20, BIT=1<<N;
int n, m;
string s;
int cnt[N][N];
int bsI[BIT];
int totCnt[N][BIT];
int mem[BIT];

int getOff(int bs) {
    int cnt=0;
    RE(i,N) if((bs & (1<<i)) == 0) cnt++;
    return cnt;
}
inline int lsb(int bs) {
    return (bs & (-bs));
}
int getTotCnt(int i, int bs) {
    bs = bs&(~(1<<i));
    if(totCnt[i][bs] == -INF) {
        int l = lsb(bs);
        totCnt[i][bs] = getTotCnt(i, bs-l)-2*cnt[i][bsI[l]];
    }
    return totCnt[i][bs];
}
int getAns(int bs) {
    if(mem[bs] == -1) {
        int x = getOff(bs);
        mem[bs] = INF;
        int nbs=bs;
        while(nbs != 0) {
            int l = lsb(nbs);
            mem[bs] = min(mem[bs], getAns(bs ^ l)+x*getTotCnt(bsI[l], bs));
            nbs -= l;
        }
    }
    return mem[bs];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>s;
    RE(i,N) RE(j,N) cnt[i][j]=0;
    RE(i,n-1) cnt[s[i]-'a'][s[i+1]-'a']++, cnt[s[i+1]-'a'][s[i]-'a']++;
    RE(i,N) RE(j,BIT) totCnt[i][j]=-INF;
    RE(i,N) {
        int tot=0;
        RE(j,N) tot+=cnt[i][j];
        tot-=cnt[i][i];
        totCnt[i][0] = tot;
    }
    RE(i,N) bsI[1<<i] = i;
    RE(i,BIT) mem[i] = -1;
    mem[0] = 0;
    cout<<getAns(BIT-1)<<endl;
}