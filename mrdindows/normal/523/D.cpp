#include <iostream>
#include <stdio.h>
#include <set>
using namespace std;
int main()
{int n,k,si,mi,min,minj,p;
ios::sync_with_stdio(0);
cin>>n>>k;
long long r[n];
std::multiset<long long> d;
for(int i=0;i<n;i++)
{cin>>si>>mi;
std::set<long long>::iterator it = d.begin();
p=0;

if(i<k){d.insert(mi+si);r[i]=mi+si;p=1;}
if(p==0){
    if(*it<si){d.insert(mi+si);d.erase(it);r[i]=mi+si;}
    else {
    d.insert(*it+mi);d.erase(it);r[i]=mi+*it;}
    }

}for(int i=0;i<n;i++)
cout<<r[i]<<endl;
}