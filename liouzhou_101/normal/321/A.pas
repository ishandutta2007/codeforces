uses
	math;

const
	INF:int64=1000000000000000000;

var
	tx,ty,n,i,k : longint;
	s : string;
	a : array[-110..110,-110..110] of longint;
	L,R,nx,ny,x,y : int64;

begin
	readln(tx,ty);
	readln(s);
	n:=length(s);
	a[0][0]:=1;
	for i:=1 to n do begin
		if s[i]='U' then y:=y+1;
		if s[i]='D' then y:=y-1;
		if s[i]='L' then x:=x-1;
		if s[i]='R' then x:=x+1;
		a[x][y]:=1;
	end;
	if (x=0) and (y=0) then begin
		if (abs(tx)<=100) and (abs(ty)<=100) then
			if a[tx][ty]=1 then begin
				writeln('Yes');
				exit;
			end;
		writeln('No');
		exit;
	end;
	L:=0;
	R:=INF;
	if x>0 then begin
		L:=max(L,trunc((tx-100)/x)-1);
		R:=min(R,round((tx+100)/x)+1);
	end;
	if x<0 then begin
		L:=max(L,trunc((tx+100)/x)-1);
		R:=min(R,round((tx-100)/x)+1);
	end;
	if y>0 then begin
		L:=max(L,trunc((ty-100)/y)-1);
		R:=min(R,round((ty+100)/y)+1);
	end;
	if y<0 then begin
		L:=max(L,trunc((ty+100)/y)-1);
		R:=min(R,round((ty-100)/y)+1);
	end;
	for k:=L to R do begin
		nx:=tx-x*k;
		ny:=ty-y*k;
		if (abs(nx)<=100) and (abs(ny)<=100) then
			if a[nx][ny]=1 then begin
				writeln('Yes');
				exit;
			end;
	end;
	writeln('No');
end.