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
string a,b;
int main(){
	cin>>a>>b;
	int n=a.length();
	if(n<b.length()){
		sort(a.begin(),a.end());
		reverse(a.begin(),a.end());
		cout<<a<<'\n';
	}else{
		sort(a.begin(),a.end());
		rep(i,n){
			int j=i;
			for(;j<n&&a.substr(0,i)+string(1,a[j])+a.substr(i,j-i)+a.substr(j+1)<=b;j++);j--;
			a=a.substr(0,i)+string(1,a[j])+a.substr(i,j-i)+a.substr(j+1);
		}
		cout<<a<<'\n';
	}
	return 0;
}