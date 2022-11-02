#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>

using namespace std;

#define For(i,n) for(i=0;i<(n);i++)
#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define pb push_back
#define ll long long

const int mod=1e9+7;

int main(){
#pragma comment(linker, "/STACK:268435456")
#ifdef HOME
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int a,s,t,i,j,n,s1,s2,k,x1,x2,last;
    vector<int> p1,p2;
    pair<int,int> one=make_pair(0,0);
    vector<pair<int,int> > ans;
    scanf("%d",&n);
    vector<pair<int,int>> l(n,one);
    For(i,n){
        scanf("%d",&a);
        if(a==1){
            p1.pb(i);
            if(i!=0) l[i]=l[i-1];
            l[i].first++;
        }
        else{
            p2.pb(i);
            if(i!=0) l[i]=l[i-1];
            l[i].second++;
        }
    }
    FOR(t,1,n+1){
        s1=0;
        s2=0;
        last=0;
        x1=x2=-1;
        k=-1;
        while(x1+t<p1.size()||x2+t<p2.size()){
            if(x1+t<p1.size()&&x2+t<p2.size()){
                k=min(p1[x1+t],p2[x2+t]);
                if(p1[x1+t]<p2[x2+t]){
                    s1++;
                    last=1;
                }else{
                    s2++;
                    last=2;
                }
            }else{
                if(x1+t<p1.size()){
                    k=p1[x1+t];
                    s1++;
                    last=1;
                }else{
                    k=p2[x2+t];
                    s2++;
                    last=2;
                }
            }
            x1=l[k].first-1;
            x2=l[k].second-1;
        }
        if(k==n-1&&s1!=s2){
            if(s1<s2){
                if(last==2){
                    ans.pb(make_pair(s2,t));
                }
            }
            if(s1>s2){
                if(last==1){
                    ans.pb(make_pair(s1,t));
                }
            }
        }
    }
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    For(i,ans.size()){
        printf("%d %d\n",ans[i].first,ans[i].second);
    }



    return 0;
}