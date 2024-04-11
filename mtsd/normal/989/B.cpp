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
    int n,p;
    cin >> n >> p;
    string s;
    cin >> s;
    bool flag = 0;
    for(int i=0;i<n;i++){
        if(i+p>=n)break;
        if(s[i]=='.'){
            flag = 1;
            if(s[i+p]=='0'){
                s[i] = '1';
            }else if(s[i+p]=='1'){
                s[i] = '0';
            }else{
                s[i]='0';
                s[i+p]='1';
            }
            break;
        }else if(s[i+p]=='.'){
            flag = 1;
            if(s[i]=='0'){
                s[i+p]='1';
            }else{
                s[i+p]='0';
            }
            break;
        }else{
            if(s[i]!=s[i+p]){
                flag = 1;
                break;
            }
        }
    }
    if(flag){
        for(int i=0;i<n;i++){
            if(s[i]=='.'){
                cout << 0;
            }else{
                cout << s[i];
            }
        }
        cout << endl;
    }else{
        cout << "No" <<endl;
    }
    return 0;
}