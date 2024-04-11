#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
	long long n;
	string answer = "EASY";
	cin >> n;
	vector <long long> a(n);
    for (long long i=1;i<=n;i++)
    {
        cin >> a[i];
        
        
    }
    for (long long j=1;j<=n;j++)
    {
        if (a[j]==1)
        answer="HARD";
        
        
        
    }
cout << answer;

}