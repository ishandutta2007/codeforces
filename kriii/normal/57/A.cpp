#include <stdio.h>
#define min(a,b) ((a<b)?(a):(b))

int N,sx,sy,ex,ey,P;

inline int abs(int a){return (a<0)?-a:a;}

int main()
{
	scanf ("%d %d %d %d %d",&N,&sx,&sy,&ex,&ey);

	if ((sx == 0 && ex == 0) || (sx == N && ex == N)) P = abs(sy-ey);
	else if ((sy == 0 && ey == 0) || (sy == N && ey == N)) P = abs(sx-ex);
	else{
		if (sx == 0 && ey == 0) P = sy + ex;
		else if (sx == 0 && ey == N) P = N - sy + ex;
		else if (sx == N && ey == 0) P = sy + N - ex;
		else if (sx == N && ey == N) P = N - sy + N - ex;
		else if (ex == 0 && sy == 0) P = ey + sx;
		else if (ex == 0 && sy == N) P = N - ey + sx;
		else if (ex == N && sy == 0) P = ey + N - sx;
		else if (ex == N && sy == N) P = N - ey + N - sx;
		else if (sx == 0 && ex == N) P = min(sy+ey,N+N-sy-ey)+N;
		else if (ex == 0 && sx == N) P = min(sy+ey,N+N-sy-ey)+N;
		else if (sy == 0 && ey == N) P = min(sx+ex,N+N-sx-ex)+N;
		else if (ey == 0 && sy == N) P = min(sx+ex,N+N-sx-ex)+N;
	}

	printf ("%d\n",P);

	return 0;
}