#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int> > s;
vector<int> t;
char d[300005];
vector<vector<int> > xc;
vector<vector<int> > yc;
int pr;
int g[2][4];
int p[2];
int np[2];
int bp[3];
int bv=-1;
int cv;
int test_x() {
	int rt=0;
	for(int j=0;j<m;j++) {
		if(j%2==0) {
			for(int i=0;i<4;i++) g[0][i]=g[1][i]=0;
			for(int i=0;i<n;i++) {
				g[i%2][s[i][j]]++;
			}
			if(g[0][p[0]]+g[1][p[1]]>g[0][p[1]]+g[1][p[0]]) {
				rt+=g[0][p[0]]+g[1][p[1]];
				for(int i=0;i<n;i++) {
					if(i%2==0) xc[i][j]=p[0];
					else xc[i][j]=p[1];
				}
			}
			else {
				rt+=g[0][p[1]]+g[1][p[0]];
				for(int i=0;i<n;i++) {
					if(i%2==0) xc[i][j]=p[1];
					else xc[i][j]=p[0];
				}
			}
		}
		else {
			for(int i=0;i<4;i++) g[0][i]=g[1][i]=0;
			for(int i=0;i<n;i++) {
				g[i%2][s[i][j]]++;
			}
			if(g[0][np[0]]+g[1][np[1]]>g[0][np[1]]+g[1][np[0]]) {
				rt+=g[0][np[0]]+g[1][np[1]];
				for(int i=0;i<n;i++) {
					if(i%2==0) xc[i][j]=np[0];
					else xc[i][j]=np[1];
				}
			}
			else {
				rt+=g[0][np[1]]+g[1][np[0]];
				for(int i=0;i<n;i++) {
					if(i%2==0) xc[i][j]=np[1];
					else xc[i][j]=np[0];
				}
			}
		}
	}
	return rt;
}
int test_y() {
	int rt=0;
	for(int i=0;i<n;i++) {
		if(i%2==0) {
			for(int j=0;j<4;j++) g[0][j]=g[1][j]=0;
			for(int j=0;j<m;j++) {
				g[j%2][s[i][j]]++;
			}
			if(g[0][p[0]]+g[1][p[1]]>g[0][p[1]]+g[1][p[0]]) {
				rt+=g[0][p[0]]+g[1][p[1]];
				for(int j=0;j<m;j++) {
					if(j%2==0) yc[i][j]=p[0];
					else yc[i][j]=p[1];
				}
			}
			else {
				rt+=g[0][p[1]]+g[1][p[0]];
				for(int j=0;j<m;j++) {
					if(j%2==0) yc[i][j]=p[1];
					else yc[i][j]=p[0];
				}
			}
		}
		else {
			for(int j=0;j<4;j++) g[0][j]=g[1][j]=0;
			for(int j=0;j<m;j++) {
				g[j%2][s[i][j]]++;
			}
			if(g[0][np[0]]+g[1][np[1]]>g[0][np[1]]+g[1][np[0]]) {
				rt+=g[0][np[0]]+g[1][np[1]];
				for(int j=0;j<m;j++) {
					if(j%2==0) yc[i][j]=np[0];
					else yc[i][j]=np[1];
				}
			}
			else {
				rt+=g[0][np[1]]+g[1][np[0]];
				for(int j=0;j<m;j++) {
					if(j%2==0) yc[i][j]=np[1];
					else yc[i][j]=np[0];
				}
			}
		}
	}
	return rt;
}
void shuffle_x() {
	int f=0;
	for(int i=0;i<4;i++) {
		for(int j=i+1;j<4;j++) {
			p[0]=i;
			p[1]=j;
			f=0;
			for(int k=0;k<4;k++) {
				if(k!=p[0] && k!=p[1]) np[f++]=k;
			}
			cv=test_x();
			if(bv==-1 || cv>bv) {
				bv=cv;
				bp[0]=i;
				bp[1]=j;
				bp[2]=0;
			}
		}
	}
}
void shuffle_y() {
	int f=0;
	for(int i=0;i<4;i++) {
		for(int j=i+1;j<4;j++) {
			p[0]=i;
			p[1]=j;
			f=0;
			for(int k=0;k<4;k++) {
				if(k!=p[0] && k!=p[1]) np[f++]=k;
			}
			cv=test_y();
			if(bv==-1 || cv>bv) {
				bv=cv;
				bp[0]=i;
				bp[1]=j;
				bp[2]=1;
			}
		}
	}
}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++) {
		scanf("%s",d);
		t.clear();
		for(int j=0;j<m;j++) {
			if(d[j]=='A') t.push_back(0);
			if(d[j]=='T') t.push_back(1);
			if(d[j]=='G') t.push_back(2);
			if(d[j]=='C') t.push_back(3);
		}
		s.push_back(t);
		xc.push_back(t);
		yc.push_back(t);
	}
	shuffle_x();
	//cout<<"?"<<endl;
	shuffle_y();
	//cout<<"?"<<endl;
	p[0]=bp[0];
	p[1]=bp[1];
	int f=0;
	f=0;
	for(int k=0;k<4;k++) {
		if(k!=p[0] && k!=p[1]) np[f++]=k;
	}
	if(bp[2]==0) {
		test_x();
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(xc[i][j]==0) printf("A");
				if(xc[i][j]==1) printf("T");
				if(xc[i][j]==2) printf("G");
				if(xc[i][j]==3) printf("C");
			}
			printf("\n");
		}
	}
	else {
		test_y();
		for(int i=0;i<n;i++) {
			for(int j=0;j<m;j++) {
				if(yc[i][j]==0) printf("A");
				if(yc[i][j]==1) printf("T");
				if(yc[i][j]==2) printf("G");
				if(yc[i][j]==3) printf("C");
			}
			printf("\n");
		}
	}
	return 0;
}