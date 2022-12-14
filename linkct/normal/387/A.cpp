#include <stdio.h>

int nh, nm, sh, sm;

void decrease_hour()
{
	nh = nh ? nh - 1 : 23;
	return;
}
void decrease_minute()
{
	if(nm)
		nm --;
	else
	{
		decrease_hour();
		nm = 59;
	}
	return;
}
int main()
{
	scanf("%d:%d", &nh, &nm);
	scanf("%d:%d", &sh, &sm);
	while(sh > 0)
	{
		decrease_hour();
		sh --;
	}
	while(sm > 0)
	{
		decrease_minute();
		sm --;
	}
	printf("%02d:%02d\n", nh, nm);
	return 0;
}