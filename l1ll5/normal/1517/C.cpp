#include <bits/stdc++.h>
#define N 505
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n;
int p[N];

vector<int> v;
int q[N][N];
void solve(int x) {

}
int main() {
    //freopen("line1.in","r",stdin);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> p[i],v.push_back(p[i]), q[i][i] = p[i];

    for(int i=2;i<=n;i++) {
        vector<int> vp;
        int mn = n + 1;
        for (int j = 0; j < v.size(); j += 1) {
            if(v[j] != i - 1) vp.push_back(v[j]);
        }
        int curx = i, cury = 1;
        for (int j = 1; j <= n - i + 1; j += 1) {
            q[curx][cury] = vp[j - 1];
            curx ++, cury ++;
        }
        v = vp;
        //for (int i = 0; i < vp.size(); i += 1) {
    }
    for(int i=1;i<=n;i++) {
        for (int j = 1; j <= i; j += 1) {
            cout << q[i][j] << ' ';
        }
        cout << '\n';
    }
}