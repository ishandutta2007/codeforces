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
using namespace std;
typedef long long int LL;
typedef pair<int,int> P;
typedef pair<LL,int> LP;
const int INF=1<<30;
const LL MAX=1e9+7;

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

LL t[1100000];

int main(){
    LL n,m;
    int i,j,k;
    LL a,b,c;
    LL p,q,r;
    LL s=1;
    cin>>n>>m;
    vector<LL> v1;
    for(i=0;i<n;i++){
        cin>>a;
        v1.push_back(a);
        s+=a-2;
    }
    if(s<m){
        cout<<-1<<endl;
        return 0;
    }
    sort(v1.rbegin(),v1.rend());
    t[0]=1,t[1]=-1;
    s=0;
    p=1e6,q=1,r=0;
    for(i=0,j=0;i<1e6;i++){
        if(i)t[i]+=t[i-1];
        for(;t[i] && j<n;j++){
            t[i]--,t[i+1]++;
            if(p==i)r--;
            if(i<=p)q--;
            t[i+2]+=2;
            a=i+2+v1[j]/2;
            if(v1[j]%2==1){
                t[a]-=2;
                q+=max(0LL,2*min(p-i-1,v1[j]/2));
                if(i+2<=p && p<a)r+=2;
            }else{
                t[a-1]--,t[a]--;
                if(i+2<=p && p<a-1)q+=(p-i-1)*2,r+=2;
                else if(a-1<=p){
                    q+=v1[j]-1;
                    if(p==a-1)r++;
                }
            }
            for(;q-r>=m;p--){
                q-=r;
                r-=t[p];
            }
        }
    }
    cout<<p<<endl;
}