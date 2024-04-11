#include<bits/stdc++.h>
using namespace std;
struct point {
	int x,y,c;
	int ind;
	point() {
		x=0;
		y=0;
		c=0;
		ind=0;
	}
	point(int xi,int yi,int ci,int indi) {
		x=xi;
		y=yi;
		c=ci;
		ind=indi;
	}
};
int n;
point a[2000];
bool operator <(point i,point j) {
	return i.x<j.x || (i.x==j.x && i.y<j.y);
}
int orient(int i,int j,int k) {
	return (a[j].x-a[i].x)*(a[k].y-a[i].y)-(a[j].y-a[i].y)*(a[k].x-a[i].x);
}
int orient(point i,point j,point k) {
	return (j.x-i.x)*(k.y-i.y)-(j.y-i.y)*(k.x-i.x);
}
bool cmp(point i,point j) {
	return orient(a[0],i,j)>0;
}
stack<int> d;
int next_to_top()
{
	int i,j;
	i=d.top();
	d.pop();
	j=d.top();
	d.push(i);
	return j;
}
void Graham()
{
	d.push(0);
	d.push(1);
	d.push(2);
	for(int i=3;i<n;i++) {
		while(d.size()>=2 && orient(next_to_top(),d.top(),i)<0) d.pop();
		d.push(i);
	}
}
int index[2000];
int m;
vector<int> tr;
bool inside(int i,int j,int k,int l) {
	int x,y,z;
	x=orient(i,j,l);
	y=orient(j,k,l);
	z=orient(k,i,l);
	//cout<<a[i].ind<<" "<<a[j].ind<<" "<<a[k].ind<<" "<<a[l].ind<<endl;
	//cout<<x<<" "<<y<<" "<<z<<endl;
	if(x>0 && y>0 && z>0) return true;
	return false;
}
void triangulate(int u,int v,int k,vector<int> beg) {
	vector<int> dr;
	//cout<<a[u].ind<<" "<<a[v].ind<<" "<<a[k].ind<<endl;
	for(int i=0;i<beg.size();i++) {
		if(inside(u,v,k,beg[i])) dr.push_back(beg[i]);
	}
	//cout<<dr.size()<<endl;
	int nk=-1;
	for(int i=0;i<dr.size();i++) {
		//cout<<a[dr[i]].ind<<" ";
		if(a[dr[i]].c==a[k].c) {
			nk=dr[i];
			break;
		}
	}
	//cout<<endl;
	if(nk==-1) {
		for(int i=0;i<dr.size();i++) printf("%d %d\n",a[u].ind,a[dr[i]].ind);
		return;
	}
	printf("%d %d\n",a[k].ind,a[nk].ind);
	triangulate(u,v,nk,dr);
	triangulate(nk,k,u,dr);
	triangulate(k,nk,v,dr);
}
int bin[2000];
int main()
{
	int x,y,c,b=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++) {
		scanf("%d %d %d",&x,&y,&c);
		a[i]=point(x,y,c,i);
		if(c==0) b++;
	}
	if(n==1 || (n==2 && a[0].c!=a[1].c)) {
		printf("0\n");
		return 0;
	}
	if(n==2) {
		printf("1\n");
		printf("0 1\n");
		return 0;
	}
	sort(a,a+n);
	sort(a+1,a+n,cmp);
	Graham();
	while(d.size()>0) {
		index[m++]=d.top();
		//cout<<a[index[m-1]].ind<<endl;
		d.pop();
	}
	int p=0;
	if(a[index[0]].c!=a[index[m-1]].c) p++;
	for(int i=1;i<m;i++) {
		if(a[index[i]].c!=a[index[i-1]].c) p++;
	}
	if(p>2) {
		printf("Impossible");
		return 0;
	}
	if(p==0) {
		if(b==0 || b==n) {	
		printf("%d\n",(n-1));
			for(int i=1;i<n;i++) printf("%d %d\n",0,i);
			return 0;
		}
		printf("%d\n",(n-2));
		for(int i=0;i<m-1;i++) {
			printf("%d %d\n",a[index[i]].ind,a[index[i+1]].ind);
		}
		int k;
		for(int i=0;i<n;i++) {
			if(a[i].c!=a[index[0]].c) {
				k=i;
				break;
			}
		}
		int u,v;
		for(int i=0;i<n;i++) tr.push_back(i);
		for(int i=0;i<m;i++) {
			u=index[i];
			if(i==m-1) v=index[0];
			else v=index[i+1];
			triangulate(v,u,k,tr);
		}
		return 0;
	}
	printf("%d\n",(n-2));
	int start_ind=0;
	for(int i=1;i<m;i++) {
		//cout<<a[index[i]].ind<<" "<<a[index[i]].c<<endl;
		if(a[index[i]].c!=a[index[i-1]].c) {
			//cout<<i<<endl;
			start_ind=i;
			break;
		}
	}
	for(int i=0;i<n;i++) tr.push_back(i);
	for(int i=0;i<m;i++) bin[i]=index[(start_ind+i)%m];
	for(int i=0;i<m;i++) index[i]=bin[i];
	int second_ind=0;
	/*for(int i=0;i<m;i++) cout<<a[index[i]].ind<<" ";
	cout<<endl;*/
	for(int i=1;i<m;i++) {
		if(a[index[i]].c!=a[index[i-1]].c) {
			second_ind=i;
			break;
		}
	}
	//cout<<a[index[0]].ind<<" "<<a[index[second_ind]].ind<<endl;
	//cout<<second_ind<<endl;
	for(int i=0;i+1<second_ind;i++) {
		printf("%d %d\n",a[index[i]].ind,a[index[i+1]].ind);
		triangulate(index[i+1],index[i],index[second_ind],tr);
	}
	for(int i=second_ind;i+1<m;i++) {
		printf("%d %d\n",a[index[i]].ind,a[index[i+1]].ind);
		triangulate(index[i+1],index[i],index[0],tr);
	}
	return 0;
}