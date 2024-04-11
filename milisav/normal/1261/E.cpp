#include<bits/stdc++.h>
using namespace std;
vector<int> g[2000];
int a[2000];
int r[2000];
char s[2000][2000];
int n;
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n+1;i++) {
        for(int j=0;j<n;j++) s[i][j]='0';
        s[i][n]=0;
        g[0].push_back(i);
    }
    int m=1;
    for(int i=0;i<n;i++) {
        int pj=0;
        for(int j=0;j<m;j++) {
            if(g[j].size()>1) {
                pj=j;
                break;
            }
        }
        while(a[i]>0 && g[pj].size()>1) {
            a[i]--;
            s[g[pj].back()][i]='1';
            g[m].push_back(g[pj].back());
            g[pj].pop_back();
        }
        for(int j=0;j<m && a[i]>0;j++) {
            if(j!=pj) {
                for(int k=0;k<g[j].size() && a[i]>0;k++) {
                    s[g[j][k]][i]='1';
                    a[i]--;
                }
            }
        }
        m++;
    }
    printf("%d\n",n+1);
    for(int i=0;i<n+1;i++) printf("%s\n",s[i]);
    return 0;
}