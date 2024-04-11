#include <algorithm>
#include <iostream>
#include <numeric>

using namespace std;

int main() {
	unsigned int n, k, i, j;
	int r;
 	
	cin >> n;
	cin >> k;
	
	int a[n];
	
	for(i=0;i<n;i++)
		cin >> a[i];
	
	i = 0;
	r = 0;
	
	while(i<k && a[i]<0) {
  		r -= a[i];
		i++;          
    }
    
    for(j=i;j<n;j++)
    	r += a[j];
    
    if(i<k && (k-i)%2 == 1) {
		if(i!=0 && ((-a[i-1])<a[i]))
			r += 2 * a[i-1];
		else
			r -= 2 * a[i];
	}
	
	cout << r << endl;

	return 0;
}