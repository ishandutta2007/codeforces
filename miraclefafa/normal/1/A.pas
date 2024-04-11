var
	a,b,n:int64;
begin
	readln(a,b,n);
	a:=(a-1)div n+1;b:=(b-1)div n+1;
	a:=a*b;
	writeln(a);
end.