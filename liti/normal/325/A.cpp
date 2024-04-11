#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;

int ax1[5],ax2[5],ay1[5],ay2[5];
int n;

bool check ( vector< pair<int, int> > x, vector< pair<int,int > > y ) 
{
	
	int minX = 31401 ,minY= 31401,maxX=-1,maxY=-1;

	for(int i =0 ; i < x.size() ; i++ )
	{
		if ( x[i].second < minX ) 
			minX = x[i].second; 
		if ( x[i].first > maxX )
			maxX = x[i].first; 
		if ( y[i].second < minY ) 
			minY = y[i].second;
		if ( y[i].first > maxY ) 
			maxY = y[i].first;
	}

	long long r = ( max(maxX- minX, maxY - minY) ) ;
	r *= r;
//	cout << r << endl;
	//cout << maxX << ' ' << minX << ' ' << maxY << ' ' << minY << endl;	
	for(int i = 0  ;i < x.size() ; i++ )
	{
		r -= ( ( x[i].first - x[i].second ) * ( y[i].first - y[i].second ) ) ; 
	}
//	cout << r << endl;
	if ( r== 0 ) 
		return true;
	return false;
}

bool calc( int t, vector< pair<int, int> >  x, vector< pair<int, int> > y )
{
//	cout << t << endl;
	if ( t != 0  ) 
	{
		int tax1 = ax1[t-1], tax2 = ax2[t-1], tay1= ay1[t-1], tay2=ay2[t-1];
		
		if ( tax1 != tax2 ) 
		{
			x.push_back( make_pair( tax1, tax2) )   ; 
			y.push_back( make_pair( tay1, tay2 ));
		}
		if ( check( x, y )  == 1 ) 
			return true;

	}
	if ( t == n ) 
		return false; 

	for(int i = t + 1 ; i <= n ;i++ )
	{
		if ( calc ( i , x, y ) == true ) 
			return true;
	}

	return false; 
}
int main() 
{

	cin >> n;
	for(int i  = 0 ; i <  n;i++ )
	{
		int tax1,tax2,tay1,tay2;
		cin >> tax1 >> tay1 >> tax2 >> tay2; 

		ax1[i] = max( tax1, tax2 )  ;
		ax2[i] = min( tax1, tax2 ) ; 
		ay1[i] = max( tay1,  tay2 ) ;  
		ay2[i] = min( tay1, tay2 ) ; 
	}
	vector<pair<int, int> > x, y; 
	for(int i = 0 ; i < n ;i++ ) 
	{
		x.push_back( make_pair( ax1[i], ax2[i] ) ) ; 
		y.push_back( make_pair( ay1[i], ay2[i] ) ) ; 
	}
//	bool ans = calc( 0,  x, y )  ;
	bool ans = check ( x,y);
	if ( ans == 0 ) 
		cout << "NO" << endl;
	else
		cout << "YES" << endl;

}