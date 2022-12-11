program project1;

var
   x,y : array[1..100000] of int64;
   i,n : longint;
   ans, sqx, sqy, sy, sx : int64;
begin
     read(n);
     sy:=0;
     sx:=0;
     sqx:=0;
     sqy:=0;
     ans:=0;
     for i:=1 to n do begin
         read(x[i],y[i]);
         sy:=sy + y[i];
         sx:=sx + x[i];
         sqx:=sqx + x[i] * x[i];
         sqy:=sqy + y[i] * y[i];
     end;
     for i:=1 to n do begin
         ans:=ans - 2 * y[i] * sy ;
         ans:=ans + (int64(n) * y[i] * y[i]) + sqy;
     end;
     for i:=1 to n do begin
         ans:=ans - 2 * x[i] * sx ;
         ans:=ans + (int64(n) * x[i] * x[i]) + sqx;
     end;
     writeln(ans div 2);
end.