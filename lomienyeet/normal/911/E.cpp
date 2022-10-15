#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,k,ptr=1;
	cin>>n>>k;
	int arr[n];
	for(int i=0;i<k;i++)cin>>i<:arr:>;
	stack<int> s;
	s.push(n+1);
	for(int i=0;i<n;i++){
		if(i>=k)i<:arr:>=s.top()-1;
		s.push(i<:arr:>);
		while(s.size()&&s.top()==ptr){
			s.pop();
			ptr++;
		}
	}
	if(s.size())cout<<"-1\n";
	else{
		for(int i=0;i<n;i++)cout<<i<:arr:><<" ";
	}
}