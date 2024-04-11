#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int n,m,qq,bit[maxn],ct[maxn],x,ans[maxn];
vector<pair<long long,int>> q;
vector<int> b[maxn];
vector<pair<vector<int>,int>> a;
int get(int idx){
    int sum=0;
    while(idx>0){
        sum+=(bit[idx]);
        idx-=(idx&(-idx));
    }
    return sum;
}
void update(int idx,int val){
    while(idx<=m){
        bit[idx]+=val;
        idx+=(idx&(-idx));
    }
    return;
}
int findk(int k){
    int pos=0,sum=0;
    for(int i=19;i>=0;i--){
        if((pos+(1<<i)<=m)&&(sum+bit[pos+(1<<i)]<k)){
            pos+=(1<<i);
            sum+=(bit[pos]);
        }
    }
    return pos+1;
}

int main(){
    scanf("%d%d%d",&n,&m,&qq);
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        ct[x]++;
    }
    for(int i=1;i<=m;i++){
        b[ct[i]].push_back(i);
    }
    for(int i=0;i<=n;i++){
        if(!b[i].empty()){
            a.push_back(make_pair(b[i],i));
        }
    }
    q.resize(qq);
    for(int i=0;i<qq;i++){
        scanf("%lld",&q[i].first);
        q[i].first-=n;
        q[i].second=i;
    }
    sort(q.begin(),q.end());
    long long cur=1LL,next;
    if(a.size()==1)next=1e18+maxn;
    else{
        next=cur+(1LL*(a[1].second-a[0].second)*((int)a[0].first.size()));
    }
    //cout<<"cur and next: "<<cur<<' '<<next<<'\n';
   /* for(auto i:a){
        printf("%d\n",i.second);
        for(int j:i.first){
            printf("%d ",j);
        }
        printf("\n");
    }*/
    for(int j:a[0].first)
        update(j,1);
    int pt=0;
    int sum=a[0].first.size();
    for(auto ss:q){
            long long i=ss.first;
        while(i>=next){
            cur=next;
            ++pt;
            if(pt==(int)a.size()-1){
                next=1e18+maxn;
                sum+=(int)a[pt].first.size();
            }
            else{
                sum+=(int)a[pt].first.size();
                next=cur+(1LL*(a[pt+1].second-a[pt].second)*sum);
            }
            for(int j:a[pt].first){
                update(j,1);
            }
        }
        //if(i==2)cout<<"here: "<<cur<<' '<<next<<' '<<sum<<'\n';

        i-=cur;
        int pos=(i)%sum;
        pos++;
        ans[ss.second]=findk(pos);
        //printf("%d\n",findk(pos));
    }
    for(int i=0;i<qq;i++)
        printf("%d\n",ans[i]);
}