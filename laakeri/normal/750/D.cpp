#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

const int R=500;
const int C=500;

int c[555][555];
int h[555][555][8];
int nh[555][555][8];

pair<int, int> dir[8];

int t[33];

void draw(int y, int x, int le, int d){
	for (int i=0;i<le;i++){
		y+=dir[d].F;
		x+=dir[d].S;
		c[y][x]=1;
	}
	nh[y][x][d]=1;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	dir[0]={0, 1};
	dir[1]={1, 1};
	dir[2]={1, 0};
	dir[3]={1, -1};
	dir[4]={0, -1};
	dir[5]={-1, -1};
	dir[6]={-1, 0};
	dir[7]={-1, 1};
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>t[i];
	}
	for (int i=250;i<250+t[0];i++){
		c[i][250]=1;
	}
	h[250+t[0]-1][250][2]=1;
	
	for (int it=1;it<n;it++){
		for (int i=0;i<R;i++){
			for (int ii=0;ii<C;ii++){
				for (int d=0;d<8;d++){
					nh[i][ii][d]=0;
				}
			}
		}
		for (int i=0;i<R;i++){
			for (int ii=0;ii<C;ii++){
				for (int d=0;d<8;d++){
					if (h[i][ii][d]){
						draw(i, ii, t[it], (d+1)%8);
						draw(i, ii, t[it], (d+7)%8);
					}
				}
			}
		}
		
		for (int i=0;i<R;i++){
			for (int ii=0;ii<C;ii++){
				for (int d=0;d<8;d++){
					h[i][ii][d]=nh[i][ii][d];
				}
			}
		}
	}
	int v=0;
	for (int i=0;i<R;i++){
		for (int ii=0;ii<C;ii++){
			v+=c[i][ii];
		}
	}
	cout<<v<<endl;
}