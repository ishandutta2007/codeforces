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
    string s;
    cin >> s;
    int n = s.size();
    bool flag =0;
    for(int i=1;i<n-1;i++){
        set<char>st;
        st.insert(s[i-1]);
        st.insert(s[i]);
        st.insert(s[i+1]);
        if(st.count('.')==0){
            if(st.size()==3){
                flag =1;
            }
        }
    }
    if(flag)cout << "Yes" << endl;
    else cout <<"No" << endl;
    return 0;
}