#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <cstdio>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007

long long  mod = 1000000007;

int main(){
	int n;
	cin >> n;
	int p[10]={};
	vector<pair<int,int> > v;
	for(int i=0;i<n;i++){
		char x;
		int y;
		int tmp;
		scanf(" %c",&x);
		scanf(" %d",&tmp);
		if(x=='&'){
			y = 0;
		}else if(x=='|'){
			y = 1;
		}else{
			y = 2;
		}
		v.PB(MP(y,tmp));
	}
	for(int i=0;i<n;i++){
		int y = v[i].first;
		int x = v[i].second;
		if(y==0){
			for(int i=0;i<10;i++){
				if(x&(1<<i)){
					continue;
				}else{
					p[i] = 1;
				}
			}
		}else if(y==1){
			for(int i=0;i<10;i++){
				if(x&(1<<i)){
					p[i] = 2;
				}else{
					continue;
				}
			}


		}else{
			for(int i=0;i<10;i++){
				if(x&(1<<i)){
					p[i] = 3-p[i];
				}else{
					continue;
				}
			}

		}
	}
	int x=0,y=0,z=0;
	for(int i=0;i<10;i++){
		if(p[i]==1){
			x += 1<<i;
		}else if(p[i]==2){
			y += 1<<i;
		}else if(p[i]==3){
			z += 1<<i;
		}
	}
	cout << 3 <<endl;
	cout << "& " << 1023-x << endl;
	cout << "| " << y <<endl;
	cout << "^ " << z << endl;
	return 0;
}