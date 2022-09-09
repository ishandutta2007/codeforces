#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,y=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')y=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*y;
}
const int maxn = 250005;
vector<int> akk[maxn];
int n,m,pos;
int noi[maxn];
int wei[maxn],cnt;
bool qieke()
{
    int mx = 0;
    for(int i=1;i<=n;++i){
        int ct = 0;
        for(int j=1;j<=m;++j){
            if(akk[i][j] != noi[j]){
                ct ++;
            }
        }
        mx = max(mx,ct);
    }
    if(mx <= 2) return 1;
    return 0;
}
int ljh[maxn];
bool check(int x)
{
    int ak = -1;
    for(int i=1;i<=n;++i) ljh[i] = 0;
    for(int i=1;i<=n;++i){
        int ct = 0;
        for(int j=1;j<=m;++j){
            if(j == x) continue;
            if(akk[i][j] != noi[j]){
                ct ++;///kk
            }
        }
        if(ct > 2) return 0;//
        if(ct == 2) ak = i;
        ljh[i] = ct;
    }
    for(int i=1;i<=n;++i){
        if(akk[i][x] != akk[ak][x] && ljh[i] == 2){
            return 0;
        }
    }
    printf("Yes\n");
    for(int i=1;i<=m;++i){
        if(i != x) printf("%d ",noi[i]);
        else printf("%d ",akk[ak][x]);
    }
    return 1;
}
void solve()
{
    for(int i=0;i<16;++i){
        for(int j=1;j<=m;++j) noi[j] = akk[1][j];
        for(int j=0;j<4;++j){
            if(i & (1<<j)){
                noi[wei[j+1]] = akk[pos][wei[j+1]];
            }
        }
        if(qieke()){
            printf("Yes\n");
            for(int j=1;j<=m;++j) printf("%d ",noi[j]);
            return;
        }
    }
    printf("No\n");
    return;
}
void work()
{
    for(int i=1;i<=3;++i){
        for(int j=1;j<=m;++j) noi[j] = akk[1][j];
        noi[wei[i]] = akk[pos][wei[i]];
        for(int j=1;j<=3;++j){
            if(i == j) continue;
            if(check(j))
                return;
        }
    }
    printf("No\n");
    return;
}
signed main()
{
    n = read(),m = read();
    for(int i=1;i<=n;++i){
        akk[i].push_back(0);
        for(int j=1;j<=m;++j){
            int x = read();
            akk[i].push_back(x);
        }
    }
    int mxx = 0;
    for(int i=2;i<=n;++i){
        int ct = 0;
        for(int j=1;j<=m;++j){
            if(akk[i][j] != akk[1][j])
                ct ++;
        }
        if(ct > mxx){
            mxx = ct;
            pos = i;
        }
    }
    if(mxx <= 2){
        printf("Yes\n");
        for(int i=1;i<=m;++i) printf("%d ",akk[1][i]);
        return 0;
    }
    if(mxx > 4){
        printf("No\n");
        return 0;
    }
    for(int i=1;i<=m;++i){
        if(akk[1][i] != akk[pos][i]){
            wei[++cnt] = i;
        }
    }
    if(mxx == 4){
        solve();
        return 0;
    }
    if(mxx == 3){
        work();
    }
}
/*
3 3
1 2 3
4 5 3
2 3 6
*/