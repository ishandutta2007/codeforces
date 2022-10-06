#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007

int main(){
	int v[25]={};
	for(int i=1;i<25;i++){
		cin >> v[i];
	}
	int a=-1,b=-1;
	for(int i=1;i<=21;i+=4){
		bool flag = 1;
		for(int j=0;j<3;j++){
			if(v[i+j]!=v[i+j+1])flag = 0;
		}
		if(flag){
			if(a==-1){
				a = i;
			}else{
				b = i;
			}
		}
	}
	if(a==-1||b==-1){
		cout << "NO" << endl;
		return 0;
	}
	if(a==1&&b==9){
		for(int i=5;i<24;i+=2){
			if(v[i]!=v[i+1]){
				cout << "NO" << endl;
				return 0;
			}
		}
		int x[] = {v[5],v[17],v[21],v[13]};
		int y[] = {v[7],v[19],v[23],v[15]};
		bool flag = 1;
		for(int i=0;i<4;i++){
			if(x[i]!=y[(i+1)%4]){
				flag = 0;
			}
		}
		if(flag){
			cout << "YES" << endl;
			return 0;
		}
		flag = 1;
		for(int i=0;i<4;i++){
			if(x[i]!=y[(i+3)%4]){
				flag = 0;
			}
		}
		if(flag){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}else if(a==13&&b==17){
		for(int i=1;i<23;i++){
			if(i%4==3||i%4==0)continue;
			if(v[i]!=v[i+2]){
				cout << "NO" << endl;
				return 0;
			}
		}
		int x[] = {v[1],v[5],v[9],v[24]};
		int y[] = {v[2],v[6],v[10],v[23]};
		bool flag = 1;
		for(int i=0;i<4;i++){
			if(x[i]!=y[(i+1)%4]){
				flag = 0;
			}
		}
		if(flag){
			cout << "YES" << endl;
			return 0;
		}
		flag = 1;
		for(int i=0;i<4;i++){
			if(x[i]!=y[(i+3)%4]){
				flag = 0;
			}
		}
		if(flag){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}else if(a==5&&b==21){
		if(v[1]!=v[2]||v[3]!=v[4]||v[9]!=v[10]||v[11]!=v[12]||v[13]!=v[15]||v[14]!=v[16]||v[17]!=v[19]||v[18]!=v[20]){
			cout << "NO" << endl;
			return 0;
		}
		int x[] = {v[3],v[17],v[10],v[16]};
		int y[] = {v[1],v[18],v[12],v[15]};
		bool flag = 1;
		for(int i=0;i<4;i++){
			if(x[i]!=y[(i+1)%4]){
				flag = 0;
			}
		}
		if(flag){
			cout << "YES" << endl;
			return 0;
		}
		flag = 1;
		for(int i=0;i<4;i++){
			if(x[i]!=y[(i+3)%4]){
				flag = 0;
			}
		}
		if(flag){
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}else{
		cout << "NO" << endl;
	}
	return 0;
}