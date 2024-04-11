#include <bits/stdc++.h>
#define N 205
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int T;
int n, m;
int b[N][N];
int c[N][N];
int r[N];
struct zgz {
    int x, y;
    int val;
    friend bool operator < (zgz &a, zgz &b) {
        return a.val < b.val;
    }
};
vector<zgz> v;

int main() {
    //freopen("line1.in","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> T;
    while(T--) {
        cin >> n >> m;
        v.clear();
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++) {
            cin >> b[i][j];
            v.push_back((zgz){i,j,b[i][j]});
        }
        for(int i=1;i<=n;i+=1) r[i] = 0;
        sort(v.begin(),v.end());
        for(int i=1;i<=m;i+=1) {
            zgz t = v[i - 1];
            r[t.x] ++;
        }
        int cur = 0;
        for(int i=1;i<=n;i++) {
            sort(b[i] + 1, b[i] + m + 1);
            cur += r[i];
            reverse(b[i] + 1, b[i] + cur + 1);
        }
        for(int i = 1;i<=n;i += 1) {
            for(int j = 1; j <= m; j+= 1) {
                cout << b[i][j] << ' ';
            }
            cout << '\n';
        }

    }
}