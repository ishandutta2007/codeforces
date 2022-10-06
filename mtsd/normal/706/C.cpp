#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

long long n,cost;
vector <long long> c;
vector<string> s1;
vector<string> s2;
string word;	
long long nor[100001];
int nor_flag[100001];
long long rev[100001];
int rev_flag[100001];
long long calc(int k);
long long rev_calc(int k);

long long calc(int k){
	long long ans1,ans2;
	ans1=-1;
	ans2=-1;
	if(k == (s1.size()-1)){
		return 0;
	}
	if(s1[k]>s1[k+1]&&s1[k]>s2[k+1]){
		return -1;
	}
	if(s1[k]<=s1[k+1]){
		if(nor_flag[k+1]==0){
			nor[k+1] = calc(k+1);
			nor_flag[k+1]=1;
		}
		ans1 = nor[k+1];
	}
	if(s1[k]<=s2[k+1]){
		if(rev_flag[k+1]==0){
			rev[k+1] = rev_calc(k+1);
			rev_flag[k+1]=1;
		}
		ans2 = rev[k+1];
	}
	if(ans1==-1){
		if(ans2==-1)return -1;
		return ans2;
	}else{
		if(ans2==-1)return ans1;
		if(ans1<ans2)return ans1;
		return ans2;
	}

}

long long rev_calc(int k){
	long long ans1,ans2;
	ans1=-1;
	ans2=-1;
	if(k== (s1.size()-1)){
		return c[k];
	}
	if(s2[k]>s1[k+1]&&s2[k]>s2[k+1]){
		return -1;
	}
	if(s2[k]<=s1[k+1]){
		if(nor_flag[k+1]==0){
			nor[k+1] = calc(k+1);
			nor_flag[k+1]=1;
		}
		if(nor[k+1]==-1) ans1 = -1;
		else ans1 = c[k]+nor[k+1];
	}
	if(s2[k]<=s2[k+1]){
		if(rev_flag[k+1]==0){
			rev[k+1] = rev_calc(k+1);
			rev_flag[k+1]=1;
		}
		if(rev[k+1]==-1) ans2 =-1;
		else ans2 = c[k]+rev[k+1];
	}
	if(ans1==-1){
		if(ans2==-1)return -1;
		return ans2;
	}else{
		if(ans2==-1)return ans1;
		if(ans1<ans2)return ans1;
		return ans2;
	}

}



int main(){
	for(int p=0;p<100001;p++){
		nor[p]=-1;
		rev[p]=-1;
	}
	cin >>n;
	for(int i=0;i<n;i++){
		cin >> cost;
		c.push_back(cost);
	}
	for(int j=0;j<n;j++){
		cin >> word;
		s1.push_back(word);
		reverse(word.begin(),word.end());
		s2.push_back(word);
	}
	long long ans,sna;
	ans = calc(0);
	sna = rev_calc(0);
	if(ans==-1){
		if(sna==-1)cout << -1 << endl;
		else cout << sna <<endl;
	}else{
		if(sna==-1)cout << ans <<endl;
		else if(ans < sna)cout << ans << endl;
		else cout << sna << endl;
	}
	return 0;
}