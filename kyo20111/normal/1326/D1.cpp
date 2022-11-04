#include<bits/stdc++.h>
using namespace std;
using ll = long long;

#define all(x) (x).begin(), (x).end()
int t, p[2002002];
char s[1001001], a[2002002];

vector<pair<int, int>> sv1[1001001], sv2[1001001];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%s",s+1);

        int n = strlen(s+1);
        int m = n;

        if(n == 1){
            printf("%s\n",s+1);
            continue;
        }

        for(int i=1;i<=m;i++) sv1[i].clear(), sv2[i].clear();

        for(int i=1;i<=2*n+1;i++) a[i] = i%2 ? '#' : s[i/2];
        n = 2*n+1;

        int r=1, k=1;
        for(int i=1;i<=n;i++){
            p[i] = max(min(r-i, p[2*k-i]), 0);
            while(i-p[i]>1 && i+p[i]<n && a[i-p[i]-1]==a[i+p[i]+1]) p[i]++;
            if(i+p[i] > r) r=i+p[i],k=i;


            int u = (i - p[i] + 1) /2;
            sv1[u].push_back({p[i], i});
            u = (i + p[i] - 1) /2;
            sv2[u].push_back({p[i], i});
        }

        int L = 0, R = m+1, cnt = 0;
        pair<int, int> mx = {0, 0}, nx, g1 = {0, 0}, g2 = {0, 0};
        while(L+1 < R-1){
            if(s[L] == s[R]){
                g1.first-=2, g2.first-=2;
                for(auto x : sv1[L+1]) if(x.second + x.first < R*2) g1 = max(g1, x);
                for(auto x : sv2[R-1]) if(x.second - x.first > L*2) g2 = max(g2, x);

                pair<int, int> u = max(g1, g2);
                if(u.first + cnt*2 > mx.first){
                    mx = {u.first + cnt*2, cnt};
                    nx = u;
                }

                L++, R--;
                cnt++;
            }
            else break;
        }

        for(int i=1;i<=mx.second;i++) printf("%c",s[i]);
        if(nx.second) for(int i=nx.second-nx.first;i<=nx.second+nx.first;i++) if(a[i] != '#') printf("%c",a[i]);
        for(int i=m-mx.second+1;i<=m;i++) printf("%c",s[i]);

        puts("");
    }
}