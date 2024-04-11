program strings;
var
    a,b:array[1..100000]of char;
function main:boolean;
var
    na,nb,i,t:longint;
    c:array[1..4]of longint;
begin
    na:=0; nb:=0; t:=0;
    while not eoln do begin
	inc(na);
	read(a[na]);
    end;
    readln;
    while not eoln do begin
	inc(nb);
	read(b[nb]);
    end;
    readln;
    if na<>nb then exit(false);
    for i:=1 to na do begin
	if a[i]<>b[i] then begin
	    inc(t);
	    c[t]:=i;
	    if t>2 then exit(false);
	end;
    end;
    if (t=2)and(a[c[1]]=b[c[2]])and(a[c[2]]=b[c[1]]) then exit(true);
    exit(false);
end;
begin
    if main then writeln('YES') else writeln('NO');
end.