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
    int ques2(int n,int m,int x1,int y1,int x2,int y2){
        int s;
        assert(x1+n<=x2 || y1+m<=y2);
        cout<<"? "<<n<<" "<<m<<" "<<x1+1<<" "<<y1+1<<" "<<x2+1<<" "<<y2+1<<endl;
        cin>>s;
        return s;
    }
    bool ques(int n,int m,int a,int div,bool rot){
        int x1,x2,n2,m2;
        if(a<n){
            int c=a-a/div;
            x1=0,x2=n-c;
            if(!rot)return ques2(c,m,x1,0,x2,0);
            else return ques2(m,c,0,x1,0,x2);
        }
        x1=0,x2=n2=a/div*(div/2),m2=m;
        int y1=0,y2=0;
        if(rot)swap(x1,y1),swap(x2,y2),swap(n2,m2);
        int s=ques2(n2,m2,x1,y1,x2,y2);
        if(s==0)return false;
        if(div==2)return true;
        x1=0,n2=a/div*(div/2),m2=m,y1=0,y2=0;
        x2=n2+a/div;
        if(rot)swap(x1,y1),swap(x2,y2),swap(n2,m2);
        return ques2(n2,m2,x1,y1,x2,y2);
    }

    int calc(int n,int m,bool rot){
        int i,j,k;
        int a,b,c;
        int s=1;
        a=b=n;
        for(i=2;i<=n;i++){
            for(j=0;b%i==0;j++){
                if(!ques(n,m,a,i,rot))break;
                a/=i,b/=i;
            }
            s*=j+1;
            for(;b%i==0;b/=i);
        }
        return s;
    }

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        cin>>n>>m;
        int s=calc(n,m,false)*calc(m,n,true);
        cout<<"! "<<s<<endl;
    }
}

int main(){
    sol::solve();
}