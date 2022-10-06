#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    vector<string>s;
    string tmp1,tmp2;
    for(int i=0;i<25;i++){
        tmp1.push_back('A');
        tmp2.push_back('C');
    }
    for(int i=0;i<25;i++){
        tmp1.push_back('B');
        tmp2.push_back('D');
    }
    for(int i=0;i<25;i++){
        s.push_back(tmp1);
    }
    for(int i=0;i<25;i++){
        s.push_back(tmp2);
    }
    a--;b--;c--;d--;
    bool flag = 0;
    for(int i=0;i<24;i+=2){
        for(int j=0;j<24;j+=2){
            if(b==0)break;
            s[i][j]='B';
            b--;
        }
        if(b==0)break;
    }
    for(int i=0;i<24;i+=2){
        for(int j=26;j<=49;j+=2){
            if(a==0)break;
            s[i][j]='A';
            a--;
        }
        if(a==0)break;
    }
    for(int i=26;i<50;i+=2){
        for(int j=0;j<24;j+=2){
            if(d==0)break;
            s[i][j]='D';
            d--;
        }
        if(d==0)break;
    }
    for(int i=26;i<50;i+=2){
        for(int j=26;j<50;j+=2){
            if(c==0)break;
            s[i][j]='C';
            c--;
        }
        if(c==0)break;
    }
    cout << "50 50" << endl;
    for(int i=0;i<50;i++){
        cout << s[i] << endl;
    }
    return 0;
}