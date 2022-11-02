#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

string t;

int cnt[11];

string gg(){
	string r;
	for (int i=0;i<10;i++){
		for (int j=0;j<cnt[i];j++){
			r+=(char)(i+'0');
		}
	}
	return r;
}

string get(){
	int f=0;
	int m=t.size();
	int fd=t[0]-'0';
	int ff=0;
	int fl=0;
	for (int i=0;i<m;i++){
		if (ff==0&&t[i]!=t[0]){
			ff=1;
			fd=t[i]-'0';
		}
		if (ff==0) fl++;
		cnt[t[i]-'0']--;
		if (cnt[t[i]-'0']<0) f=1;
	}
	int oz=1;
	for (int i=1;i<10;i++){
		if (cnt[i]>0) oz=0;
	}
	if (f==1||(oz==1&&t[0]=='0')){
		for (int i=0;i<m;i++){
			cnt[t[i]-'0']++;
		}
		return "";
	}
	
	string v;
	int ut=0;
	string v1;
	if (t[0]!='0'){
		v1=t+gg();
	}
	string v2;
	if (oz==0){
		int fu=0;
		for (int i=1;i<10;i++){
			if (cnt[i]>0){
				fu=i;
				cnt[i]--;
				v2+=(char)(i+'0');
				break;
			}
		}
		for (int i=0;i<10;i++){
			if (ut==0&&((t[0]-'0')<i||((t[0]-'0')==i&&fd<i))){
				v2+=t;
				ut=1;
			}
			for (int j=0;j<cnt[i];j++){
				v2+=(char)(i+'0');
			}
		}
		if (ut==0){
			v2+=t;
		}
		
		cnt[fu]++;
	}
	
	for (int i=0;i<m;i++){
		cnt[t[i]-'0']++;
	}
	
	if ((int)v1.size()>0&&(int)v2.size()>0) return min(v1, v2);
	else if((int)v1.size()>0) return v1;
	else return v2;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string ss;
	cin>>ss>>t;
	sort(ss.begin(), ss.end());
	if (ss=="01"){
		cout<<0<<endl;
		return 0;
	}
	int n=ss.size();
	for (int i=0;i<n;i++){
		cnt[ss[i]-'0']++;
	}
	string vv;
	for (int le=1;le<=n;le++){
		int x=le;
		int f=0;
		int s=0;
		while (x>0){
			s++;
			cnt[x%10]--;
			if (cnt[x%10]<0) f=1;
			x/=10;
		}
		if (f==0&&n-s==le){
			string asd=get();
			if ((int)asd.size()>0){
				if ((int)vv.size()==0) vv=asd;
				else{
					if ((int)asd.size()<(int)vv.size()||((int)asd.size()==(int)vv.size()&&asd<vv)){
						vv=asd;
					}
				}
			}
		}
		
		x=le;
		while (x>0){
			cnt[x%10]++;
			x/=10;
		}
	}
	cout<<vv<<endl;
}