

program untitled;

var
	n,k,killed,jab:int64;
	i:longint;
	bsum,arr:array[1..200000] of int64;
	alive:array[1..200000] of boolean;


BEGIN
	readln(n,k);
	for i:=1 to n do read(arr[i]);
	killed:=0;
	for i:=1 to n do alive[i]:=true;
	bsum[1]:=0;
	for i:=2 to n do begin
		if alive[i-1] then bsum[i]:=bsum[i-1]+arr[i-1]*(i-2-killed) else bsum[i]:=bsum[i-1];
		//writeln(i,' ',bsum[i]-(i-1-killed)*(n-i)*arr[i]);
		{kol:=0;
		bsum[i]:=0;
		for j:=1 to i-1 do if alive[j] then begin
			bsum[i]:=bsum[i]+arr[j]*kol;
			inc(kol)
		end;}
		jab:=bsum[i]-(i-1-killed)*(n-i)*arr[i];
		if jab<k then begin
			inc(killed);
			writeln(i);
			alive[i]:=false
		end
	end
END.