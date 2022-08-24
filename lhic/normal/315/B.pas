

program untitled;
var
	n,m,y,k,i,a,b:longint;
	arr:array[1..100000] of longint;

BEGIN
	readln(n,m);
	for i:=1 to n do read(arr[i]);
	k:=0;
	for i:=1 to m do begin
		read(y);
		if y=1 then begin
			readln(a,b);
			arr[a]:=b-k
		end;
		if y=2 then begin
			readln(a);
			k:=k+a
		end;
		if y=3 then begin
			readln(a);
			writeln(arr[a]+k)
		end
	end
END.