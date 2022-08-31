


program untitled;

var
	arr:array[0..2000000] of int64;
	n4,a,k,step,step2:int64;
	i:longint;
	max:int64;


procedure chan(a,b:int64);
var
	q:int64;
begin
	q:=arr[a];
	arr[a]:=arr[b];
	arr[b]:=q
end;

procedure qsort(a,b:int64);
var
	qm,m,l,r,q:int64;
begin
	qm:=a+random(b-a+1);
	q:=arr[qm];
	l:=a;
	m:=a+1;
	r:=b;
	chan(a,qm);
	while m<=r do if arr[m]=q then inc(m) else
		if arr[m]>q then begin
			chan(m,l);
			inc(l);
			inc(m)
		end
		else begin
			chan(m,r);
			dec(r)
		end;
	if l-a>1 then qsort(a,l-1);
	if b-r>1 then qsort(r+1,b)
end;


BEGIN
	randomize;
	readln(n4);
	for i:=1 to n4 do read(arr[i]);
	a:=n4;
	k:=1;
	while a>1 do begin 
		a:=a div 4;
		inc(k)
	end;
	qsort(1,n4);
	step2:=1;
	max:=0;
	step:=1;
	while step2<=n4 do begin
		while step<=step2 do begin
			max:=max+arr[step]*k;
			inc(step)
		end;
		dec(k);
		step2:=step2*4;
	end;
	writeln(max)
end.
	 
	
END.