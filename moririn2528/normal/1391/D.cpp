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

vector<string> v1;
int check(vector<int>& v2){
    int i,j,k;
    int a,b;
    if(v2.size()<6){
        v2.push_back(0);
        a=check(v2);
        v2.pop_back();
        v2.push_back(1);
        b=check(v2);
        v2.pop_back();
        return min(a,b);
    }
    if((v2[0]+v2[1]+v2[3]+v2[4])%2==0 || (v2[2]+v2[1]+v2[5]+v2[4])%2==0)return INF;
    a=0;
    for(i=0;i<v1.size();i++){
        b=0;
        for(j=0;j<3;j++){
            k=(i%2)*3+j;
            if((int)v1[i][j]-(int)'0'!=v2[k])b++;
        }
        a+=min(b,3-b);
    }
    return a;
}

int main(){
    int n,m;
    int i,j,k;
    int a,b,c;
    scanf("%d%d",&n,&m);
    v1.assign(n,string());
    for(i=0;i<n;i++){
        cin>>v1[i];
    }
    if(n==1 || m==1){
        cout<<0<<endl;
        return 0;
    }
    if(n>=4 && m>=4){
        cout<<-1<<endl;
        return 0;
    }
    if(n<m){
        vector<string> v2=v1;
        v1.assign(m,string(n,0));
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                v1[j][i]=v2[i][j];
            }
        }
        swap(n,m);
    }
    if(m==2){
        b=0;
        for(i=0;i<2;i++){
            a=0;
            for(j=0;j<n;j++){
                c=0;
                for(k=0;k<2;k++){
                    c+=(int)v1[j][k]-(int)'0';
                }
                if(c%2!=(i+j)%2)a++;
            }
            swap(a,b);
        }
        cout<<min(a,b)<<endl;
        return 0;
    }
    vector<int> vs;
    cout<<check(vs)<<endl;

}