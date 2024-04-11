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
void array_show(vector<int> &vec_s,char middle=' '){
    for(int i=0;i<vec_s.size();i++)printf("%d%c",vec_s[i],(i!=vec_s.size()-1?middle:'\n'));
}
void array_show(vector<LL> &vec_s,char middle=' '){
    for(int i=0;i<vec_s.size();i++)printf("%lld%c",vec_s[i],(i!=vec_s.size()-1?middle:'\n'));
}
 
vector<int> vr[100005],vl[100005];
vector<P> v1;
 
int main(){
    LL n,m,p;
    int i,j,k;
    LL a,b,c;
    cin>>n>>m>>p;
    for(i=0;i<p;i++){
        cin>>a>>b;
        a--,b--;
        v1.push_back(make_pair(a,b));
    }
    sort(v1.begin(),v1.end());
    for(auto t:v1){
        vr[t.first].push_back(t.second);
        vl[t.second].push_back(t.first);
    }
    LL nr[2]={0,m-1},nl[2]={0,n-1};
    int x=0,y=0;
    LL s=1;
    while(nr[0]<=nr[1] || nl[0]<=nl[1]){
        if(!vr[x].empty()){
            auto itr=upper_bound(vr[x].begin(),vr[x].end(),y);
            if(itr!=vr[x].end() && (*itr)<=nr[1])nr[1]=(*itr)-1;
        }
        if(x>0 && y==nr[1])break;
        s+=nr[1]-y,y=nr[1];
        nl[0]++;
        if(nr[0]>nr[1] || nl[0]>nl[1])break;
        if(!vl[y].empty()){
            auto itr=upper_bound(vl[y].begin(),vl[y].end(),x);
            if(itr!=vl[y].end() && (*itr)<=nl[1])nl[1]=(*itr)-1;
        }
        if(x==nl[1])break;
        s+=nl[1]-x,x=nl[1];
        nr[1]--;
        if(nr[0]>nr[1] || nl[0]>nl[1])break;
 
        if(!vr[x].empty()){
            auto itr=upper_bound(vr[x].begin(),vr[x].end(),y);
            if(itr!=vr[x].begin()){
                itr--;
                if(nr[0]<=(*itr))nr[0]=(*itr)+1;
            }
        }
        if(y==nr[0])break;
        s+=y-nr[0],y=nr[0];
        nl[1]--;
        if(nr[0]>nr[1] || nl[0]>nl[1])break;
        if(!vl[y].empty()){
            auto itr=upper_bound(vl[y].begin(),vl[y].end(),x);
            if(itr!=vl[y].begin()){
                itr--;
                if(nl[0]<=(*itr))nl[0]=(*itr)+1;
            }
        }
        if(x==nl[0])break;
        s+=x-nl[0],x=nl[0];
        nr[0]++;
    }
    s+=p;
    if(s==n*m)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}