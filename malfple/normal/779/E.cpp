#include <iostream>
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

#define repp(i,a,b,d) for(int i=a;i<=b;i+=d)
#define rep(i,a,b) repp(i,a,b,1)
#define revv(i,a,b,d) for(int i=a;i>=b;i-=d)
#define rev(i,a,b) revv(i,a,b,1)

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

struct data{
    int type; // 0->standalone, 1->get from previous indexes
    string v;
    int jumpa;
    int jumpb;
    int opr; // 0 AND, 1 OR, 2 XOR
};

const int N = 5005;

int n,m;
map<string, int>mep;
data arr[N];
int buffer[N];

int main(){
    ios_base::sync_with_stdio(0);
    mep["?"] = 0;

    cin>>n>>m;
    rep(i,1,n){
        string str;
        cin>>str;
        mep[str] = i;

        cin>>str;

        cin>>str;
        if(str[0] == '0' || str[0] == '1'){
            arr[i].type = 0;
            arr[i].v = str;
        }else{
            arr[i].type = 1;
            arr[i].jumpa = mep[str];

            cin>>str;
            if(str[0] == 'A')arr[i].opr = 0;
            else if(str[0] == 'O')arr[i].opr = 1;
            else if(str[0] == 'X')arr[i].opr = 2;

            cin>>str;
            arr[i].jumpb = mep[str];
        }
    }

    //rep(i,1,n)printf("%d %s %d %d %d\n",arr[i].type, arr[i].v.c_str(), arr[i].jumpa, arr[i].jumpb, arr[i].opr);

    string strmin;
    string strmax;

    rep(z,0,m-1){
        int cnt0 = 0, cnt1 = 0;

        //try 0
        buffer[0] = 0;
        rep(i,1,n){
            if(arr[i].type == 0){
                buffer[i] = arr[i].v[z] - '0';
            }else{
                int a = buffer[arr[i].jumpa];
                int b = buffer[arr[i].jumpb];

                switch(arr[i].opr){
                    case 0:
                        buffer[i] = a & b;
                        break;
                    case 1:
                        buffer[i] = a | b;
                        break;
                    case 2:
                        buffer[i] = a ^ b;
                        break;
                }
            }
            cnt0 += buffer[i];
        }
        //rep(i,1,n)printf("%d ",buffer[i]);printf("\n");

        //try 1
        buffer[0] = 1;
        rep(i,1,n){
            if(arr[i].type == 0){
                //buffer[i] = arr[i].v[z] - '0'; //can exclude this
            }else{
                int a = buffer[arr[i].jumpa];
                int b = buffer[arr[i].jumpb];

                switch(arr[i].opr){
                    case 0:
                        buffer[i] = a & b;
                        break;
                    case 1:
                        buffer[i] = a | b;
                        break;
                    case 2:
                        buffer[i] = a ^ b;
                        break;
                }
                //printf("debug jump at try 1 >>> %d %d %d %d\n",a,b,arr[i].opr, buffer[i]);
            }
            cnt1 += buffer[i];
        }
        //rep(i,1,n)printf("%d ",buffer[i]);printf("\n");

        //printf(">%d %d\n",cnt0, cnt1);
        if(cnt0 == cnt1){
            strmax += '0';
            strmin += '0';
        }else if(cnt0 > cnt1){
            strmax += '0';
            strmin += '1';
        }else{
            strmax += '1';
            strmin += '0';
        }
    }

    cout << strmin << endl;
    cout << strmax << endl;

    return 0;
}