#include<bits/stdc++.h>
using namespace std;
const int N=110;
int n,a[N][N],x;
int now1,now2,now3,now4;
int main(){
	cin>>n;
	now1=1;now2=1;now3=1;now4=2;
	int last=n,last2=n;
	if(n%2==1)last2--;
	else last--;
	for(int i=1;i<=n*n;i++){
		cin>>x;
		if(x==1){/*2,3*/
			if(now3>n){
				a[now1][now2]=3;
				cout<<3<<" "<<now1<<" "<<now2<<endl;
				if(now2==last){
					now1++;
					if(last==n)last=n-1;
					else last=n;
					now2=(last%2==0?2:1);
				}
				else{
					now2+=2;
				}
			}
			else{
				a[now3][now4]=2;
				cout<<2<<" "<<now3<<" "<<now4<<endl;
				if(now4==last2){
					now3++;
					if(last2==n)last2=n-1;
					else last2=n;
					now4=(last2%2==0?2:1);
				}
				else{
					now4+=2;
				}
			}
		}
		else if(x==2){/*1,3*/
			if(now1>n){
				a[now3][now4]=3;
				cout<<3<<" "<<now3<<" "<<now4<<endl;
				if(now4==last2){
					now3++;
					if(last2==n)last2=n-1;
					else last2=n;
					now4=(last2%2==0?2:1);
				}
				else{
					now4+=2;
				}
			}
			else{
				a[now1][now2]=1;
				cout<<1<<" "<<now1<<" "<<now2<<endl;
				if(now2==last){
					now1++;
					if(last==n)last=n-1;
					else last=n;
					now2=(last%2==0?2:1);
				}
				else{
					now2+=2;
				}
			}
		}
		else{ /* 1,2 */
			if(now1>n){
				a[now3][now4]=2;
				cout<<2<<" "<<now3<<" "<<now4<<endl;
				if(now4==last2){
					now3++;
					if(last2==n)last2=n-1;
					else last2=n;
					now4=(last2%2==0?2:1);
				}
				else{
					now4+=2;
				}
			}
			else{
				a[now1][now2]=1;
				cout<<1<<" "<<now1<<" "<<now2<<endl;
				if(now2==last){
					now1++;
					if(last==n)last=n-1;
					else last=n;
					now2=(last%2==0?2:1);
				}
				else{
					now2+=2;
				}
			}
		}
	}
	return 0;
}