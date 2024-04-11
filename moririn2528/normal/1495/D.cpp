#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<deque>
#include<iomanip>
#include<tuple>
#include<cassert>
#include<set>
#include<complex>
#include<numeric>
#include<functional>
#include<unordered_map>
#include<unordered_set>
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=998244353;

void array_show(int *array,int array_n,char middle=' '){
    for(int i=0;i<array_n;i++)printf("%d%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(LL *array,int array_n,char middle=' '){
    for(int i=0;i<array_n;i++)printf("%lld%c",array[i],(i!=array_n-1?middle:'\n'));
}
void array_show(vector<int> &vec_s,int vec_n=-1,char middle=' '){
    if(vec_n==-1)vec_n=vec_s.size();
    for(int i=0;i<vec_n;i++)printf("%d%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}
void array_show(vector<LL> &vec_s,int vec_n=-1,char middle=' '){
    if(vec_n==-1)vec_n=vec_s.size();
    for(int i=0;i<vec_n;i++)printf("%lld%c",vec_s[i],(i!=vec_n-1?middle:'\n'));
}

namespace sol{
    vector<vector<int>> path;
    int t[444][444];
    int count[444][444];
    LL ans[444][444];

    void solve(){
        const int B=10;
        int n,m;
        int i,j,k,p;
        int a,b,c;
        cin>>n>>m;
        path.assign(n,vector<int>());
        for(i=0;i<m;i++){
            cin>>a>>b;
            a--,b--;
            path[a].push_back(b);
            path[b].push_back(a);
        }
        for(i=0;i<n;i++){
            queue<P> q1;
            vector<int> dis(n,-1),cnt(n,0);
            q1.push(make_pair(i,-1));
            for(j=0;!q1.empty();j++){
                k=q1.size();
                while(k--){
                    a=q1.front().first,b=q1.front().second;
                    q1.pop();
                    if(dis[a]!=-1 && dis[a]<j)continue;
                    if(dis[a]==j){
                        cnt[a]++;
                        continue;
                    }
                    if(b==-1)cnt[a]=1;
                    else cnt[a]+=cnt[b];
                    cnt[a]=min(cnt[a],B);
                    dis[a]=j;
                    for(auto to:path[a]){
                        if(dis[to]>j)continue;
                        q1.push(make_pair(to,a));
                    }
                }
            }
            for(j=0;j<n;j++){
                t[i][j]=dis[j];
                count[i][j]=cnt[j];
            }
        }

        for(i=0;i<n;i++){
            for(j=i;j<n;j++){
                if(count[i][j]>1)continue;
                a=t[i][j];
                vector<vector<P>> div(a+1);
                vector<P> v1(n);
                vector<int> va(n);
                for(k=0;k<n;k++){
                    b=t[i][k]-t[j][k]+a;
                    c=t[i][k]+t[k][j]-t[i][j];
                    if(b%2 || c%2)break;
                    b/=2,c/=2;
                    v1[k]=make_pair(b,c);
                }
                if(k<n)continue;
                for(k=0;k<n;k++){
                    b=v1[k].first,c=v1[k].second;
                    for(auto to:path[k]){
                        if(v1[to].first==b && v1[to].second==c+1){
                            va[to]++;
                        }
                    }
                }
                LL s=1;
                for(k=0;k<n;k++){
                    if(v1[k].second==0)continue;
                    s*=va[k];
                    s%=MAX;
                }
                ans[i][j]=ans[j][i]=s;
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(j)cout<<" ";
                cout<<ans[i][j];
            }
            cout<<endl;
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    sol::solve();
}