program Project1;

var
   nok : int64;
   i,j,a,b : int64;
   x,y : int64;

function gcd(a,b : int64):int64;
begin
     if a <> 0 then gcd:=gcd(b mod a,a) else gcd:=b;
end;

procedure return(s : string);
begin
     writeln(s);
     halt(0);
end;

begin
     read(a,b);
     nok:=a * b div gcd(a,b);
     x:=nok div a;
     y:=nok div b;
     if abs(x - y) = 1 then return('Equal');
     if x > y then return('Dasha') else return('Masha');
end.