#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<ctype.h>
#include<map>
#include<unordered_set>
using namespace std;

#define x first
#define y second
typedef long long ll;
typedef pair<int,int> Pi;

vector <int> v[100010];

unordered_set <ll> S;

Pi p[100010];

bool comp(const Pi &a,const Pi &b){return a.y!=b.y?a.y<b.y:a.x<b.x;}

int main()
{
    int n;
    scanf("%d",&n);
    int i;
    for(i=1;i<=n;i++)scanf("%d%d",&p[i].x,&p[i].y);
    for(i=1;i<=n;i++){
        v[p[i].y].push_back(p[i].x);
        S.insert(1e6*p[i].x+p[i].y);
    }
    sort(p+1,p+1+n,comp);
    int ans = 0;
    int sq = sqrt(n);
    for(i=0;i<=100000;i++){
        if((int)v[i].size() < sq){
            sort(v[i].begin(), v[i].end());
            int j, k, sz = v[i].size();
            for(j=0;j<sz;j++){
                for(k=0;k<j;k++){
                    int t = v[i][j] - v[i][k];
                    if(S.find(1e6*v[i][k]+i+t) == S.end())continue;
                    if(S.find(1e6*v[i][j]+i+t) == S.end())continue;
                    ans++;
                }
            }
        }
        else{
            int r = upper_bound(p+1,p+1+n,Pi(-1,i+1),comp) - p;
            for(int j=r;j<=n;j++){
                if(p[j].y <= i)continue;
                int t = p[j].y - i;
                if(S.find(1e6*p[j].x+i) == S.end())continue;
                if(S.find(1e6*(p[j].x+t)+i) == S.end())continue;
                if(S.find(1e6*(p[j].x+t)+i+t) == S.end())continue;
                ans++;
            }
        }
    }
    printf("%d",ans);
    return 0;
}