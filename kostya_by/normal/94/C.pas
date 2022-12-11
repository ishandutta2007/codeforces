program p1;

var
        n,m,a,b,x1,x2,y1,y2 : longint;


procedure return(x : longint);
begin
        writeln(x);
        halt(0);
end;


begin
        read(n,m,a,b);
        y1:=a mod m;
        if y1 = 0 then y1:=m;
        y2:=b mod m;
        if y2 = 0 then y2:=m;
        if a mod m = 0 then x1:=a div m else x1:=(a div m) + 1;
        if b mod m = 0 then x2:=b div m else x2:=(b div m) + 1;
        //writeln(x1,' ',y1);
        //writeln(x2,' ',y2);
        if x1 = x2 then return(1);
        if (y1 = 1) and (y2 = m) then return(1);
        if (y1 = 1) and (b = n) then return(1);
        if b = n then return(2);
        if y2 = m then return(2);
        if y1 = y2 + 1 then return(2);
        if y1 = 1 then return(2);
        if x1 = x2 - 1 then return(2);
        return(3);
end.