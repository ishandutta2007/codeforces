Program _B;
var
    d,i,ans,n,t:longint;
begin
    readln(d);
    readln(n);
    for i:=1 to n-1 do begin
	read(t);
	inc(ans,d-t);
    end;
    readln(t);
    writeln(ans);
end.