program untitled;

{$H+}

var
	s:string;
	m,n,a,b,i:longint;
	bsum:array[0..100000] of longint;

BEGIN
		readln(s);
		n:=length(s);
		bsum[0]:=0;
		for i:=1 to n-1 do if s[i]=s[i+1] then bsum[i]:=bsum[i-1]+1 else bsum[i]:=bsum[i-1];
		readln(m);
		for i:=1 to m do begin
			readln(a,b);
			writeln(bsum[b-1]-bsum[a-1])
		end
END.