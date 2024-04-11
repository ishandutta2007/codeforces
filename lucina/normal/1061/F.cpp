#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
map<tuple<int,int,int>,int> m;
int query(int x,int y,int z){
    tuple<int,int,int> w=make_tuple(x,y,z);
    if(m.find(w)!=m.end())
        return m[w];
    printf("? %d %d %d\n",x,y,z);
    fflush(stdout);
    char s[5];
    scanf("%s",s);
    return m[w]=(s[0]=='Y');
}
int n,k,h,a[1600],lf1,lf2;
vector<int> all;
int findleaf(){
    while(true){
        shuffle(a+1,a+1+n,rng);
        int leaf=a[1];
        int keep=a[2];
        bool ch=1;
        for(int i=3;i<=n;i++){
            int x=query(keep,leaf,a[i]);
            ch&=(x==0);
            if(!ch)break;
        }
        if(ch)return leaf;
    }
}
int newleaf(){
    while(true){
        shuffle(a+1,a+1+n,rng);
        if(a[1]==lf1)continue;
        int leaf=a[1],cnt=0;
        all.clear();
        for(int i=2;i<=n;i++){
            if(a[i]==lf1)continue;
            int x=query(lf1,a[i],leaf);
            cnt+=x;
            if(x)
                all.push_back(a[i]);
        }
        if(cnt==2*h-1)
            return leaf;
    }
}
void root(){
    for(int i:all){
        int cnt=0;
        for(int j:all){
            if(j==i)continue;
            cnt+=query(lf1,j,i);
        }
        if(cnt==h-1){
            printf("! %d\n",i);
            fflush(stdout);
            exit(0);
        }
    }
    printf("! 2\n");
    fflush(stdout);
    exit(0);
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        a[i]=i;
    int sum=1,g=k;
    while(sum+g<=n){
        sum+=(g);
        g*=k;
        h++;
    }
    lf1=findleaf();
    lf2=newleaf();
    root();

}