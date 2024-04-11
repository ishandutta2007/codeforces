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
typedef pair<LL,LL> LP;
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

namespace sol{

    void init(){
        
    }

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        cin>>n;
        string sa;
        cin>>sa;
        if(sa[0]=='0' || sa.back()=='0'){
            cout<<"No"<<endl;
            return;
        }
        for(i=0,a=0;i<n;i++){
            if(sa[i]=='0')a++;
        }
        if(a%2==0 && n%2==0)cout<<"Yes"<<endl;
        else{
            cout<<"No"<<endl;
            return;
        }
        a=n-a;
        b=0,c=0;
        string s1,s2;
        for(i=0;i<n;i++){
            if(sa[i]=='1'){
                if(b<a/2){
                    s1.push_back('(');
                    s2.push_back('(');
                }else{
                    s1.push_back(')');
                    s2.push_back(')');
                }
                b++;
            }else{
                if(c%2){
                    s1.push_back('(');
                    s2.push_back(')');
                }else{
                    s1.push_back(')');
                    s2.push_back('(');
                }
                c++;
            }
        }
        cout<<s1<<endl;
        cout<<s2<<endl;
    }
}

int main(){
    int n,i;
    sol::init();
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>n;
    for(i=0;i<n;i++){
        sol::solve();
    }
}