var n, i: longint;
    A: array[1..100000] of int64;

procedure swap(var x,y:int64);
var tam:int64;
begin
	tam:=x;
	x:=y;
	y:=tam;
end;

procedure qsort(l,r:int64);
var i,j,k:int64;
begin
	i:=l;	j:=r;
	k:=a[l+random(r-l+1)];
	repeat
		while a[i]<k do inc(i);
		while a[j]>k do dec(j);
		if i<=j then
		begin
			swap(a[i],a[j]);
			inc(i);
			dec(j);
		end;
	until i>j;
	if l<j then qsort(l,j);
	if i<r then qsort(i,r);
end;

begin
  read(n);
  for i := 1 to n do read(A[i]);
  qsort(1,n);
  A[1] := 1;
  for i := 2 to n do if A[i-1] < A[i] - 1 then A[i] := A[i-1] + 1;
  write(A[n] + 1);
end.