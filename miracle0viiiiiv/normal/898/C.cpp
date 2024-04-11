#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=1e9+7;
map<string,int> id;
int cnt;
vector<string> dat[25];
bool del[25][1005];
int newid(string S){
	if(id.find(S)!=id.end())return id[S];
	return id[S]=cnt++;
}
int is_suf(string x,string y){
	return y.length()>=x.length()&&y.substr(y.length()-x.length())==x;
}
int main(){
	int n,m;
	string cs;
	cin>>n;
	rep(k,n){
		cin>>cs>>m;
		int ci=newid(cs);
		rep(j,m){
			cin>>cs;
			dat[ci].push_back(cs);
		}
	}
	rep(i,cnt)rep(j,dat[i].size())rep(k,dat[i].size())
	if(j!=k&&!del[i][k]&&is_suf(dat[i][j],dat[i][k])){
		del[i][j]=true;
		break;
	}
	cout<<cnt<<'\n';
	for(map<string,int>::iterator it=id.begin();it!=id.end();it++){
		cout<<it->first;
		int cc=it->second,c2=0;
		rep(k,dat[cc].size())if(!del[cc][k])c2++;
		cout<<' '<<c2;
		rep(k,dat[cc].size())
		if(!del[cc][k])cout<<' '<<dat[cc][k];
		cout<<'\n';
	}
	return 0;
}