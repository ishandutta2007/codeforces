#include <iostream>
#include <iomanip>
#include <cstdio>

#include <cstring>
#include <string>

#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>

#include <queue>
#include <utility>
#include <set>
#include <stack>
#include <vector>
#include <map>

#define YOU using
#define DONT namespace
#define SAY std

YOU DONT SAY;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<pll> vll;

#define REPP(i,a,b,d) for(int i=a;i<=b;i+=d)
#define REP(i,a,b) REPP(i,a,b,1)
#define REVV(i,a,b,d) for(int i=a;i>=b;i-=d)
#define REV(i,a,b) REVV(i,a,b,1)

#define FOR(i,a) for(int i=0; i<a; i++)
#define FORD(i,a) for(int i=a-1; i>=0; i--)

#define mp make_pair

#define pb push_back
#define ff first
#define ss second

const int OO = 1e9;
const ll INF = 1e18;

const int irand(int lo,int hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

const ll lrand(ll lo,ll hi){
	return ((double)rand()/(RAND_MAX + 1.0)) * (hi-lo+1) + lo;
}

//end of macro

bool good[28];
string pallette;
int m;
int starpos = -1;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie();

    string str;
    cin>>str;
    FOR(i,str.size()){
        good[str[i]-'a'] = true;
    }

    cin>>pallette;

    FOR(i,pallette.size()){
        if(pallette[i] == '*'){
            starpos = i;
            break;
        }
    }

    cin>>m;
    FOR(i,m){
        cin>>str;

        bool rekt = false;
        if(starpos == -1){
            if(str.size() != pallette.size()){
                rekt = true;
            }else{
                FOR(j,pallette.size()){
                    if(pallette[j] == '?'){
                        if(!good[str[j]-'a']){
                            rekt = true;
                            break;
                        }
                    }else{
                        if(pallette[j] != str[j]){
                            rekt = true;
                            break;
                        }
                    }
                }
            }
        }else{
            if(str.size()+1 < pallette.size()){
                rekt = true;
            }else{
                int diff = (int)str.size()-pallette.size();

                REP(j,0,starpos-1){
                    if(pallette[j] == '?'){
                        if(!good[str[j]-'a']){
                            rekt = true;
                            break;
                        }
                    }else{
                        if(pallette[j] != str[j]){
                            rekt = true;
                            break;
                        }
                    }
                }
                REV(j,(int)pallette.size()-1, starpos+1){
                    if(pallette[j] == '?'){
                        if(!good[str[j+diff]-'a']){
                            rekt = true;
                            break;
                        }
                    }else{
                        if(pallette[j] != str[j+diff]){
                            rekt = true;
                            break;
                        }
                    }
                }
                REP(j,starpos,starpos+diff){
                    if(good[str[j]-'a']){
                        rekt = true;
                        break;
                    }
                }
            }
        }
        if(rekt){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
    return 0;
}