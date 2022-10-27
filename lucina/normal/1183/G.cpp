#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int T,n,a[maxn],ans;
struct pa{
    int f;
    int t;
    void cl(){
    f=0,t=0;
    }
    bool operator<(const pa x)const{
        return t==x.t?f>x.f:t>x.t;
    }
}b[maxn];
priority_queue<int> q;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n+1;i++)b[i].cl();
        int x,y;
        for(int i=1;i<=n;i++){
            scanf("%d%d",&x,&y);
            b[x].t++;
            if(y)b[x].f++;
        }
        while(!q.empty())q.pop();
        vector<int> v;
        sort(b+1,b+1+n);
        x=b[1].t;
        v.push_back(x);
        x--;
        for(int i=2;i<=n;i++){
            if(x==0||b[i].t==0)break;
            if(b[i].t>=x){
                v.push_back(x);
            }
            else{
                x=b[i].t;
                v.push_back(x);
            }
            x--;
        }
        ans=0;
        for(int i:v){
            ans+=i;
        }
        y=0;
        int pt=1;
       for(int i:v){
            while(b[pt].t>=i&&b[pt].t>0){
                q.push(b[pt].f);
                pt++;
            }
            y+=min(i,(q.top()));
            q.pop();
       }
       printf("%d %d\n",ans,y);
    }

}