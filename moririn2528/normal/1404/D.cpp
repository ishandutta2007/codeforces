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

int t[550000][2];
bool used[550000];

int main(){
    int n,m;
    int i,j,k;
    int a,b,c;
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    if(n%2==0){
        cout<<"First"<<endl;
        for(i=0;i<2*n;i++){
            if(i)cout<<" ";
            cout<<i%n+1;
        }
        cout<<endl;
        cin>>a;
        return 0;
    }
    cout<<"Second"<<endl;
    vector<int> v1,vs;
    memset(t,-1,sizeof(t));
    for(i=0;i<2*n;i++){
        cin>>a;
        a--;
        v1.push_back(a);
        if(t[a][0]!=-1)t[a][1]=i;
        else t[a][0]=i;
    }
    for(i=0;i<n;i++){
        if(used[i])continue;
        a=t[i][0],b=i;
        vs.push_back(a);
        while(1){
            used[b]=true;
            c=t[b][0]+t[b][1]-a;
            c=(c+n)%(2*n);
            if(c==t[i][0])break;
            vs.push_back(c);
            a=c,b=v1[c];
        }
    }
    sort(vs.begin(),vs.end());
    a=0;
    for(i=0;i<n;i++){
        vs[i]++;
        a+=vs[i];
        a%=2*n;
    }
    if(a){
        vector<int> v2;
        for(i=1,j=0;i<=2*n;i++){
            if(j<n && vs[j]==i){
                j++;
                continue;
            }
            v2.push_back(i);
        }
        swap(vs,v2);
    }
    for(i=0;i<n;i++){
        if(i)cout<<" ";
        cout<<vs[i];
    }
    cout<<endl;
    cin>>a;
}