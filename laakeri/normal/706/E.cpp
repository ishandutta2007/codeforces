#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

int lleft[1010101];
int rright[1010101];
int down[1010101];
int val[1010101];
int head[1010];

int n,m,q;

void updd(int i){
	if (i<0||i>=n) return;
	if (i==n-1){
		int t=head[i];
		for (int j=0;j<m+1;j++){
			down[t]=0;
			t=lleft[t];
		}
	}
	else{
		int t=head[i];
		int t2=head[i+1];
		for (int j=0;j<m+1;j++){
			down[t]=t2;
			t=lleft[t];
			t2=lleft[t2];
		}
	}
}

void setl(int t, int l){
	lleft[t]=l;
	rright[l]=t;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>q;
	int i2=1;
	for (int i=0;i<n;i++){
		head[i]=i2++;
		setl(i2-1, i2);
		for (int j=0;j<m;j++){
			int t=i2;
			i2++;
			cin>>val[t];
			if (j<m-1) setl(t, t+1);
		}
	}
	for (int i=0;i<n;i++){
		updd(i);
	}
	for (int qq=0;qq<q;qq++){
		int a,b,c,d,h,w;
		cin>>a>>b>>c>>d>>h>>w;
		a--;
		b--;
		c--;
		d--;
		if (b>d) {
			swap(b, d);
			swap(a, c);
		}
		vector<int> s1,e1,s2,e2;
		int t=head[a];
		for (int i=0;i<b+1;i++){
			t=lleft[t];
		}
		for (int i=0;i<h;i++){
			s1.push_back(t);
			t=down[t];
		}
		t=head[c];
		for (int i=0;i<d+1;i++){
			t=lleft[t];
		}
		for (int i=0;i<h;i++){
// 			cout<<"asd "<<t<<endl;
			s2.push_back(t);
			t=down[t];
		}
		t=head[a];
		for (int i=0;i<b+w;i++){
			t=lleft[t];
		}
		for (int i=0;i<h;i++){
			e1.push_back(t);
			t=down[t];
		}
		t=head[c];
		for (int i=0;i<d+w;i++){
			t=lleft[t];
		}
		for (int i=0;i<h;i++){
			e2.push_back(t);
			t=down[t];
		}
		for (int i=0;i<(int)s1.size();i++){
			//cout<<s1[i]<<" "<<s2[i]<<" "<<e1[i]<<" "<<e2[i]<<endl;
			//cout<<"lol"<<endl;
			s1[i]=rright[s1[i]];
			s2[i]=rright[s2[i]];
			//cout<<s1[i]<<" "<<s2[i]<<" "<<e1[i]<<" "<<e2[i]<<endl;
			int ls1=lleft[s1[i]];
			int ls2=lleft[s2[i]];
			int le1=lleft[e1[i]];
			int le2=lleft[e2[i]];
			if (s2[i]==e1[i]){
				setl(s1[i], ls2);
				setl(e2[i], ls1);
				setl(e1[i], le2);
			}
			else {
				setl(s1[i], ls2);
				setl(s2[i], ls1);
				setl(e1[i], le2);
				setl(e2[i], le1);
			}
		}
		updd(a-1);
		updd(a-1+h);
		updd(c-1);
		updd(c-1+h);
	}
	for (int i=0;i<n;i++){
		int t=head[i];
		for (int j=0;j<m;j++){
			t=lleft[t];
			cout<<val[t]<<" ";
		}
		cout<<'\n';
	}
}