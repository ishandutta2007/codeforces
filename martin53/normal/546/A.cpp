#include<bits/stdc++.h>
using namespace std;

int main()
{
int k, n, w;
cin>>k>>n>>w;
int outp=w*(w+1)/2*k;

cout<< max(0, outp-n) <<endl;
}