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

    bool ques(int x1,int y1,int x2,int y2,vector<vector<char>>& A){
        cout<<"? "<<x1+1<<" "<<y1+1<<" "<<x2+1<<" "<<y2+1<<endl;
        int s;
        cin>>s;
        if(x2+y2-x1-y1>2)return s;
        if(x1!=x2 && y1!=y2)swap(x1,x2),swap(y1,y2);
        if(s)A[x2][y2]=A[x1][y1];
        else A[x2][y2]=1-A[x1][y1];
        return s;
    }

    bool check(int x,int y,vector<vector<char>>& A){
        int n=A.size();
        assert(0<=x && x<n-1 && 0<=y && y<n-2);
        return A[x][y]==A[x+1][y+2] && (A[x+1][y]==A[x+1][y+1] || A[x][y+1]==A[x][y+2]);
    }

    void output(vector<vector<char>>& A){
        cout<<"!"<<endl;
        int n=A.size();
        int  i,j;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                cout<<(char)('0'+A[i][j]);
            }
            cout<<endl;
        }
    }

    void solve(){
        int n,m;
        int i,j,k;
        int a,b,c;
        cin>>n;
        vector<vector<char>> A(n,vector<char>(n)),B(n,vector<char>(n));
        A[0][0]=1;
        for(i=0;i<n-1;i+=2){
            ques(i,0,i+2,0,A);
        }
        for(i=0;i<n;i+=2){
            for(j=0;j<n-1;j+=2){
                if(i==n-1 && j+2==n-1)continue;
                ques(i,j,i,j+2,A);
            }
        }
        for(i=1;i<n;i+=2){
            for(j=1;j<n;j+=2){
                ques(i,j,i+1,j+1,A);
            }
        }
        for(i=n-1;i>=0;i--){
            for(j=1-i%2;j+2<n;j+=2){
                ques(i,j,i,j+2,A);
            }
            if(i==0)break;
            if(i%2==0)ques(i-1,0,i,1,A);
            else ques(i-1,1,i,2,A);
        }
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if((i+j)%2)B[i][j]=1-A[i][j];
                else B[i][j]=A[i][j];
            }
        }
        for(i=0;i<n-1;i++){
            for(j=0;j<n-2;j++){
                if(check(i,j,A)!=check(i,j,B)){
                    if(ques(i,j,i+1,j+2,A)==check(i,j,A))output(A);
                    else output(B);
                    return;
                }
            }
        }
        assert(false);
    }
}

int main(){
    sol::solve();
}