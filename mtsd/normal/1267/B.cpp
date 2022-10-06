#include <iostream>
#include <utility>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
#define MP make_pair
#define PB push_back
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)

int main(){
    string s;
    cin >> s;
    int n = s.size();
    char c = '.';
    int sm = 1;
    vector<pair<char,int> > p;
    for(int i=0;i<n;i++){
        if(i==0){
            c = s[i];
            sm = 1;
        }else{
            if(s[i]!=c){
                p.PB(MP(c,sm));
                sm = 1;
                c = s[i];
            }else{
                sm++;
            }
        }
    }
    p.push_back(MP(c,sm));
    if((int)p.size()%2==0){
        cout << 0 << endl;
        return 0;
    }else{
        int k = p.size()/2;
        int res = p[k].second+1;
        if(res<3)res = 0;
        int ss = k-1;
        int tt = k+1;
        while(ss>=0){
            if(p[ss].first!=p[tt].first||p[ss].second+p[tt].second < 3)res = 0;
            ss--;
            tt++;
        }
        cout << res << endl;
    }
    return 0;
}