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

int gcd(int a,int b){
    if(a<b)swap(a,b);
    if(b==0)return a;
    return gcd(b,a%b);
}

void get_line(int& a,int& b){
    int d=gcd(abs(a),abs(b));
    a/=d,b/=d;
    swap(a,b);
    b=-b;
    if(a<0)a=-a,b=-b;
}

map<LL,int> m1;
set<P> sa[220000];
map<P,int> cnt,cnt2;

int main(){
    int n,m;
    int i,j,k;
    int a,b,c;
    LL x,y,z;
    cin>>n;
    m=0;
    for(i=0;i<n;i++){
        cin>>k>>x>>y;
        if(k<=2){
            z=x*x+y*y;
            if(m1.find(z)==m1.end()){
                c=m1.size();
                m1[z]=c;
            }else c=m1[z];
        }
        if(k==1){
            for(auto node:sa[c]){
                a=node.first-x,b=node.second-y;
                get_line(a,b);
                cnt[make_pair(a,b)]++;
            }
            sa[c].insert(make_pair(x,y));
            z=gcd(x,y);
            cnt2[make_pair(x/z,y/z)]++,m++;
        }else if(k==2){
            sa[c].erase(make_pair(x,y));
            for(auto node:sa[c]){
                a=node.first-x,b=node.second-y;
                get_line(a,b);
                cnt[make_pair(a,b)]--;
            }
            z=gcd(x,y);
            cnt2[make_pair(x/z,y/z)]--,m--;
        }else{
            z=gcd(x,y);
            x/=z,y/=z;
            a=m-cnt2[make_pair(x,y)]-cnt[make_pair(x,y)]*2;
            cout<<a<<endl;
        }
    }
}